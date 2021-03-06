#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Resource/Localization.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/UI/Font.h>
#include "ExitGame.h"
#include "../Messages/Achievements.h"
#include "../Global.h"

using namespace Levels;

ExitGame::ExitGame(Context* context) :
    BaseLevel(context)
{
    timer_.Reset();
    SubscribeToEvents();
}

ExitGame::~ExitGame()
{
}

void ExitGame::RegisterObject(Context* context)
{
    context->RegisterFactory<ExitGame>();
}

void ExitGame::Init()
{
    // Disable achievement showing for this level
    GetSubsystem<Achievements>()->SetShowAchievements(false);

    CreateUI();
}

void ExitGame::SubscribeToEvents()
{
    SubscribeToEvent(E_UPDATE, URHO3D_HANDLER(ExitGame, HandleUpdate));
}

void ExitGame::HandleUpdate(StringHash eventType, VariantMap& eventData)
{
    if (timer_.GetMSec(false) > 3000) {
        GetSubsystem<Engine>()->Exit();
    }
}

void ExitGame::CreateUI()
{
    auto* localization = GetSubsystem<Localization>();
    UI* ui = GetSubsystem<UI>();
    auto *cache = GetSubsystem<ResourceCache>();
    auto *font = cache->GetResource<Font>(APPLICATION_FONT);
    
    Text* text = ui->GetRoot()->CreateChild<Text>();
    text->SetHorizontalAlignment(HA_CENTER);
    text->SetVerticalAlignment(VA_CENTER);
    text->SetStyleAuto();
    text->SetFont(font, 16);
    text->SetText(localization->Get("EXITING_GAME"));
}

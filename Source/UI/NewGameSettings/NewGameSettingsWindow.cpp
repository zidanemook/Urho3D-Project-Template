#include <Urho3D/Urho3DAll.h>
#include "NewGameSettingsWindow.h"
#include "../../MyEvents.h"
#include "../../Audio/AudioManagerDefs.h"

/// Construct.
NewGameSettingsWindow::NewGameSettingsWindow(Context* context) :
    BaseWindow(context),
    _active(true)
{
    Init();
}

NewGameSettingsWindow::~NewGameSettingsWindow()
{
}

void NewGameSettingsWindow::Init()
{
    Create();

    SubscribeToEvents();
}

void NewGameSettingsWindow::Create()
{
    Input* input = GetSubsystem<Input>();
    if (!input->IsMouseVisible()) {
        input->SetMouseVisible(true);
    }
}

void NewGameSettingsWindow::SubscribeToEvents()
{
}

void NewGameSettingsWindow::HandleUpdate(StringHash eventType, VariantMap& eventData)
{
}
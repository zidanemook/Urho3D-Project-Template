#include <Urho3D/Urho3DAll.h>
#include "PauseWindow.h"
#include "../../MyEvents.h"
#include "../../Audio/AudioManagerDefs.h"

/// Construct.
PauseWindow::PauseWindow(Context* context) :
    BaseWindow(context),
    _active(true)
{
    Init();
}

PauseWindow::~PauseWindow()
{
}

void PauseWindow::Init()
{
    Create();

    SubscribeToEvents();
}

void PauseWindow::Create()
{
    Input* input = GetSubsystem<Input>();
    if (!input->IsMouseVisible()) {
        input->SetMouseVisible(true);
    }
}

void PauseWindow::SubscribeToEvents()
{
}

void PauseWindow::HandleUpdate(StringHash eventType, VariantMap& eventData)
{
}
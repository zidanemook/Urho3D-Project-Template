#pragma once

#include <Urho3D/Urho3DAll.h>
#include "../BaseLevel.h"
#include "../Globals.h"
#include <vector>

namespace Levels {

	class MainMenu : public BaseLevel
	{
		URHO3D_OBJECT(MainMenu, BaseLevel);

	public:
		/// Construct.
		MainMenu(Context* context);

		virtual ~MainMenu();
		void HandleUpdate(StringHash eventType, VariantMap& eventData);

	protected:
		virtual void Init();

	private:
		void CreateScene();

		void CreateUI();

		void SubscribeToEvents();

		void HandleStartGame(StringHash eventType, VariantMap& eventData);

		SharedPtr<Button> _startButton;

		Timer timer;
	};
}
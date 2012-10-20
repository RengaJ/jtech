#ifndef J_GAME_H
#define J_GAME_H

#include <jobject.h>
#include <math/jvector.h>
// Managers / Contexts
#include <graphics/jgraphicscontext.h>
#include <audio/jaudiomanager.h>
#include <input/jinputmanager.h>
#include <physics/jphysicsmanager.h>
class jGame : public jObject
{
	public:
		// DEFAULT CONSTRUCTOR
		jGame();
		// FULL CONSTRUCTOR
		jGame(jGraphicsContext* graphicsContext, jInputManager* inputManager,
			  jPhysicsManager* physicsManager, jAudioManager* audioManager);
		// DESTRUCTOR
		~jGame();
		virtual initialize() = 0;
		virtual set_fullscreen(bool fullscreen) = 0;
		bool get_fullscreen();

		void set_graphics_context(jGraphicsContext* graphicsContext);
		void set_input_manager(jInputManager* inputManager);
		void set_physics_manager(jPhysicsManger* physicsManager);
		void set_audio_manager(jAudioManager* audioManager);

		jGraphicsContext* get_graphics_context();
		jInputManager* get_input_manager();
		jPhysicsManager* get_physics_manager();
		jAudioManager* get_audio_manager();

	private:
		// THE GRAPHICS CONTEXT FOR THE GAME.
		// THIS CAN BE ONE OF THE FOLLOWING (BY DEFAULT):
		//  o jD3D10Context   --> jWindowsGame
		//  o jOpenGLContext  --> jLinuxGame
		jGraphicsContext pGraphicsContext*;
		// THERE IS NO DEFAULT IMPLEMENTATION OF A jInputManager.
		// IT MUST BE SUBCLASSED PER GAME
		jInputManager pInputManager*;
		// THIS IS THE DEFAULT PHYSICS MANAGER FOR THE ENGINE.
		// IT CAN BE SUBCLASSED AND REPLACED
		jPhysicsManager pPhysicsManager*;
		// THIS IS THE DEFAULT AUDIO MANAGER FOR THE ENGINE.
		// IT CAN BE SUBCLASSED AND REPLACED
		jAudioManager pAudioManager*;
		// DETERMINES IF THE GAME IS CURRENTLY RUNNING IN FULLSCREEN MODE
		bool bIsFullscreen;
		// GAME NAME
		char* sGameName;
};

#endif

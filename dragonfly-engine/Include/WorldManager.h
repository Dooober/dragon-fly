#ifndef __WORLD_MANAGER_H__
#define __WORLD_MANAGER_H__

#include "Manager.h"
#include "ObjectList.h"
#include "Box.h"

#define WM df::WorldManager::getInstance()

namespace df {
	const int MAX_ALTITUDE = 4;

	class WorldManager : public Manager {
	private:
		WorldManager(); // Singleton
		WorldManager(WorldManager const&); // Don't allow copy
		void operator=(WorldManager const&); // Don't allow assignment

		ObjectList updates; // All Objects in world to update
		ObjectList deletions; // All Objects in world to delete
		Box boundary; // World boundary
		Box view; // Player view of game world
		Object* p_view_following; // Object view is following

	public:
		static WorldManager& getInstance(); // Get the only instance of the WorldManager
		int startUp(); // Startup game world
		void shutDown(); // Shutdown game world
		int insertObject(Object* p_o); // Insert Object into world. Return 0 if success else -1
		int removeObject(Object* p_o); // Remove Object from world. Return 0 if success else -1
		ObjectList getAllObjects() const; // Return list of all Objects in world.
		ObjectList objectsOfType(std::string type) const; // Return list of all Objects in world matching type
		void update(); // Update world, delete objects marked for deletion
		int markForDelete(Object* p_o); // Indicate Object is to be deleted at end of current game loop. Return 0 if success, else -1
		void draw(); // Draw all objects
		ObjectList getCollisions(Object* p_o, Vector where) const; // Return list of objects collided with at position 'where'.
		int moveObject(Object* p_o, Vector where); // Move object and detect collisions, return 0 if success, -1 if collision with solid object
		void setBoundary(Box new_boundary);
		Box getBoundary() const;
		void setView(Box new_view);
		Box getView() const;
		void setViewPosition(Vector view_pos); // Set view to center window on position view_pos
		int setViewFollowing(Object* p_new_view_following); // Set to NULL to stop following, return 0 if success, else -1
	};
}

#endif 


#ifndef __OBJECT_LIST_H__
#define __OBJECT_LIST_H__

#include "Object.h"
#include "ObjectListIterator.h"


namespace df {
	const int MAX_OBJECTS = 5000;
	class ObjectListIterator;

	class ObjectList {
	private:
		int count; // Count of objects in list
		Object* p_obj[MAX_OBJECTS]; // Array of pointers to objects

	public:
		friend class ObjectListIterator;
		ObjectList();
		int insert(Object* p_o); // Insert object pointer in list, return 0 if success, otherwise -1
		int remove(Object* p_o); // Remove object pointer from list, return 0 if found, else -1
		void clear(); // Clear list by setting count to 0
		int getCount() const; 
		bool isEmpty() const; 
		bool isFull() const;
	};
}

#endif


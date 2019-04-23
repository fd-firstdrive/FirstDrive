/************************************************************************/
/*                                                                      */
/* This file is part of FirstDrive.                                         */
/*                                                                      */
/* FirstDrive is free software: you can redistribute it and/or modify       */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or    */
/* (at your option) any later version.                                  */
/*                                                                      */
/* FirstDrive is distributed in the hope that it will be useful,            */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of       */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        */
/* GNU General Public License for more details.                         */
/*                                                                      */
/* You should have received a copy of the GNU General Public License    */
/* along with FirstDrive.  If not, see <http://www.gnu.org/licenses/>.      */
/*                                                                      */
/************************************************************************/

#ifndef _COLLISION_CONTACT_H
#define _COLLISION_CONTACT_H

#include "tracksurface.h"
#include "LinearMath/btVector3.h"
#include <cassert>
#include <vector>
#include <iostream> //delete

class Bezier;
class btCollisionObject;

class CollisionContact
{
public:
	CollisionContact() :
		depth(0),
		patchid(-1),
		//patch(0),
		surface(TrackSurface::None()),
		col(0)
	{
		// ctor
		patch = std::vector<const Bezier*>();
	}

	CollisionContact( //SINGLETON
		const btVector3 & p,
		const btVector3 & n,
		const btScalar d,
		const int i,
		const Bezier * b,
		const TrackSurface * s,
		const btCollisionObject * c) :
		position(p),
		normal(n),
		depth(d),
		patchid(i),
		//patch(b),
		surface(s),
		col(c)
	{
		assert(s != NULL);
		patch.push_back(b);
	}


	CollisionContact( //ARRAY
		const btVector3 & p,
		const btVector3 & n,
		const btScalar d,
		const int i,
		std::vector<const Bezier *> b,
		const TrackSurface * s,
		const btCollisionObject * c) :
		position(p),
		normal(n),
		depth(d),
		patchid(i),
		patch(b),
		surface(s),
		col(c)
	{
		assert(s != NULL);
	}

	const btVector3 & GetPosition() const
	{
		return position;
	}

	const btVector3 & GetNormal() const
	{
		return normal;
	}

	btScalar GetDepth() const
	{
		return depth;
	}

	const TrackSurface & GetSurface() const
	{
		return *surface;
	}

	int GetPatchId() const
	{
		return patchid;
	}

	const Bezier * GetPatch() const	{
		//std::cout << "0/" << patch.size() << std::endl;
		return (patch.size() > 0 ? patch[0] : NULL) ;
	}
	const Bezier * GetPatch(unsigned int idx) const	{
		//std::cout << idx << "\\" << patch.size() << std::endl;
		return (patch.size() > idx ? patch[idx] : NULL) ;
	}

	const btCollisionObject * GetObject() const
	{
		return col;
	}

	// update/interpolate contact
	bool CastRay(
		const btVector3 & origin,
		const btVector3 & direction,
		const btScalar length)
	{
		// plane-based approximation
		btScalar nd = normal.dot(direction);
		if (nd < 0)	{
			depth = normal.dot(position - origin) / nd;
			position = origin + direction * depth;
			return true;
		}
		position = origin + direction * length;
		depth = length;
		return false;
	}

private:
	btVector3 position;
	btVector3 normal;
	btScalar depth;
	int patchid;
	std::vector<const Bezier *> patch;
	const TrackSurface * surface;
	const btCollisionObject * col;
};

#endif // _COLLISION_CONTACT_H

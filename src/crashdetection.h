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

#ifndef _CRASHDETECTION_H
#define _CRASHDETECTION_H

class CrashDetection
{
public:
	CrashDetection();

	void Update(float vel, float dt);

	float GetMaxDecel() const;

private:
	float lastvel;
	float curmaxdecel;
	float maxdecel;
	float deceltrigger;
};

#endif // _CRASHDETECTION_H

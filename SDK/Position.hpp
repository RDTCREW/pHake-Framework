#ifndef _POSITION_HPP_
#define _POSITION_HPP_

#include "../Memory/Process.h"

class Position : public DataWrapper<0x58 + 0x4>
{
public:
	Position(){}
	Position(HANDLE& h) :DataWrapper(h) {}

	vector3 xyz()
	{
		return this->read<vector3>(0x50);
	}

	void xyz(vector3 value)
	{
		this->write<vector3>(0x50, value);
	}

	void xyz(float x, float y, float z)
	{
		vector3 value;
		value.x = x;
		value.y = y;
		value.z = z;

		this->write<vector3>(0x50, value);
	}

	float x()
	{
		return this->read<float>(0x50);
	}

	void x(float value)
	{
		this->write<float>(0x50, value);
	}

	float y()
	{
		return this->read<float>(0x54);
	}

	void y(float value)
	{
		this->write<float>(0x54, value);
	}

	float z()
	{
		return this->read<float>(0x58);
	}

	void z(float value)
	{
		this->write<float>(0x58, value);
	}
};

#endif
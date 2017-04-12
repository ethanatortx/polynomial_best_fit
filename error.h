#ifndef _ERROR_H
#define _ERROR_H

#include <exception>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>

namespace error
{
	struct base: std::exception
	{
		virtual void format_error_message()const=0;

		const char* what() const throw()
		{
			format_error_message();
			return error_message_buffer;
		}

		mutable char error_message_buffer[256];
	};

	struct with_errno
	{
		with_errno()
		{ errno_value = 0; }

		void set_errno(int e)
		{ this->errno_value = e; }

		int errno_value;
	};

	struct with_cartesian
	{
		with_cartesian()
		{ x = 0; y = 0; z = 0; }

		void set_x(double _x)
		{ x = _x; }
		void set_y(double _y)
		{ y = _y; }
		void set_z(double _z)
		{ z = _z; }

		double x, y, z;
	};

	struct dimensions_not_equivalent:
		base,
		with_errno
	{
		void format_error_message() const
		{
			if(this->errno_value == (int)('c'))
			{
				std::snprintf(error_message_buffer, sizeof(error_message_buffer),
					"Dimensions of cartesian coordinates not equivalent.");
			}
			else if(this->errno_value == (int)('p'))
			{
				std::snprintf(error_message_buffer, sizeof(error_message_buffer),
					"Dimensions of polar coordinates not equivalent.");
			}
			else
			{
				std::snprintf(error_message_buffer, sizeof(error_message_buffer),
					"Dimensions of coordinates not equivalent. Error number:%d", errno);
			}
		}
	};
};

#endif
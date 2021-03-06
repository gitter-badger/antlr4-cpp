/*
 *  Copyright (c) 2015 Sam Harwell, Tunnel Vision Laboratories LLC
 *  All rights reserved.
 *
 *  The source code of this document is proprietary work, and is not licensed for
 *  distribution. For information about licensing, contact Sam Harwell at:
 *      sam@tunnelvisionlabs.com
 */
#pragma once

#include <functional>
#include "param_type.hpp"

namespace antlr4 {
namespace runtime {
namespace misc {

	template<typename _Tptr>
	struct ptr_equal_to : public std::binary_function<_Tptr, _Tptr, bool>
	{
		typedef typename param_type<_Tptr>::type param_type;

		bool operator() (param_type _Left, param_type _Right) const
		{
			if (!_Left)
			{
				return !_Right;
			}
			else if (!_Right)
			{
				return false;
			}

			return *_Left == *_Right;
		}
	};

}
}
}

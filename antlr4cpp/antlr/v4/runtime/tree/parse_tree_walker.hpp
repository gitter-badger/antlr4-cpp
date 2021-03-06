/*
 *  Copyright (c) 2015 Sam Harwell, Tunnel Vision Laboratories LLC
 *  All rights reserved.
 *
 *  The source code of this document is proprietary work, and is not licensed for
 *  distribution. For information about licensing, contact Sam Harwell at:
 *      sam@tunnelvisionlabs.com
 */
#pragma once

namespace antlr4 {
namespace runtime {
namespace tree {

	class error_node;
	class parse_tree;
	class parse_tree_listener;
	class rule_node;
	class terminal_node;

	class parse_tree_walker
	{
	private:
		static parse_tree_walker _instance;

	protected:
		parse_tree_walker()
		{
		}

		virtual ~parse_tree_walker()
		{
		}

	public:
		static parse_tree_walker& instance()
		{
			return _instance;
		}

	public:
		virtual void walk(parse_tree_listener& listener, parse_tree const& tree);

	protected:
		virtual void enter_rule(parse_tree_listener& listener, rule_node const& tree);
		virtual void exit_rule(parse_tree_listener& listener, rule_node const& tree);
	};

}
}
}

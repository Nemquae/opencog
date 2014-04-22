/*
 * opencog/embodiment/Control/PerceptionActionInterface/ActionParamType.h
 *
 * Copyright (C) 2002-2009 Novamente LLC
 * All Rights Reserved
 * Author(s): Novamente team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _ACTION_PRIMITIVE_H
#define _ACTION_PRIMITIVE_H

/**
 * ActionPrimitive.h:
 *
 * Defines the types of action primitives, according with XSD, as follows:
 * <xsd:_____ value="____"/>
 * <xsd:enumeration value="int"/>
 */

namespace opencog { namespace pai {

/**
 * ActionPrimitive class. Defines the interface for the most granular effects
 * of actions.  Basic linear transforms, simple visual animations, simple
 * sound effects, etc. would be defined as action primitives from which actions
 * are composed.  As a general rule of thumb, use plans for high level
 * behaviors, actions for goal-driven behaviors which may be defined at runtime
 * and which may depend on one another, and action primitives for the simplest
 * behaviors which should be defined by all embodiments and which do not depend
 * on one another.
 */
class ActionPrimitive
{
public:
    ActionPrimitive();
};// class ActionPrimitive

} } // namespace opencog::pai

#endif//_ACTION_PRIMITIVE_H

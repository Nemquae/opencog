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

#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <opencog/atomspace/AtomSpace.h>
#include <opencog/spatial/math/Vector3.h>
#include <opencog/spatial/math/Quaternion.h>

using XERCES_CPP_NAMESPACE::DOMDocument;
using XERCES_CPP_NAMESPACE::DOMElement;

using std::string;
using std::shared_ptr;

using opencog::spatial::math::Vector3;
using opencog::spatial::math::Quaternion;

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
 * behaviors which are uniform for all embodiments and not interdependent.
 */
class ActionPrimitive
{

public:

    // err on the side of subclasses needing to deallocate pointers, etc.
    virtual ~ActionPrimitive();

    /**
     * Create an xml element in the DOMDocument XML document. An action
     * primitive element's form depends on its subtype.
     *
     * @param doc The XML document where the element will be inserted.
     * @param parent The parent element where the element will be created.
     * @return The DOMElement just created.
     */
    virtual DOMElement* toXML(const DOMDocument& doc, const DOMElement& parent)
        const = 0;

    /**
     * Create an string representation for the action primitive.
     * Standard insertion operators are defined for subtypes.
     *
     * @return The string representation of the action primitive.
     */
    virtual shared_ptr<string> toString() const = 0;

    /**
     * Get the type name as a string to identify the primitive in xml.
     *
     * @return The string repesentation of the primitive's type.
     */
    virtual shared_ptr<string> getTypeName() const = 0;

    /**
     * Get the name of the action primitive.
     *
     * @return The name of the action primitive.
     */
    const string & getName() const;

    /**
     * Set the name of the action primitive.
     *
     * @param name The name of the action primitive.
     */
    void setName(const string & name);

protected:

    /**
     * The name of the action primitive.  Mostly used to distinguish
     * action primitives in the XML.
     */
    string _name;

    /**
     * Helper function for intializing an xml element.
     *
     * @param doc The XML document where the element will be inserted.
     * @return The DOMElement just created.
     */
    static DOMElement* createElement(const DOMDocument& doc);

};// class ActionPrimitive


/**
 *
 */
class TranslationActionPrimitive : public ActionPrimitive
{
private:

    Vector3 _transVector;


public:

    TranslationActionPrimitive(const string & name, const Vector3 & transVector);
    TranslationActionPrimitive();
    TranslationActionPrimitive(const TranslationActionPrimitive & rhs);
    virtual ~TranslationActionPrimitive() {}
    TranslationActionPrimitive& operator=(const TranslationActionPrimitive & rhs);

    const Vector3 & getTransVector() const;
    void setTransVector(const Vector3 & transVector);

    virtual DOMElement* toXML(const DOMDocument& doc, const DOMElement& parent) const;

    virtual shared_ptr<string> toString() const;

    virtual shared_ptr<string> getTypeName() const;

};// class TranslationActionPrimitive



} } // namespace opencog::pai

#endif//_ACTION_PRIMITIVE_H

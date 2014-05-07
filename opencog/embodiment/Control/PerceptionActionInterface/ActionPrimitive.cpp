#include "ActionPrimitive.h"
#include "PVPXmlConstants.h"
#include "PAIUtils.h"

using XERCES_CPP_NAMESPACE::XMLString;

ActionPrimitive::~ActionPrimitive() {}

const string & ActionPrimitive::getName() const
{
    return _name;
}

DOMElement* ActionPrimitive::createElement(const DOMDocument& doc)
{
    XMLCh tag[PAIUtils::MAX_TAG_LENGTH+1];
    XMLString::transcode(PARAMETER_ELEMENT, tag, PAIUtils::MAX_TAG_LENGTH);
    DOMElement *param = doc->createElement(tag);

    XMLString::transcode(NAME_ATTRIBUTE, tag, PAIUtils::MAX_TAG_LENGTH);
    XMLCh* nameStr = XERCES_CPP_NAMESPACE::XMLString::transcode(name.c_str());
    param->setAttribute(tag, nameStr);
    XERCES_CPP_NAMESPACE::XMLString::release(&nameStr);

    XERCES_CPP_NAMESPACE::XMLString::transcode(TYPE_ATTRIBUTE, tag, PAIUtils::MAX_TAG_LENGTH);
    XMLCh* typeStr = XERCES_CPP_NAMESPACE::XMLString::transcode(type.getName().c_str());
    param->setAttribute(tag, typeStr);
    XERCES_CPP_NAMESPACE::XMLString::release(&typeStr);


}

TranslationActionPrimitive::TranslationActionPrimitive()
{
}

TranslationActionPrimitive::TranslationActionPrimitive
    (const string & name, const Vector3 & transVector)
    : _name(name)
    , _transVector(transVector)
{
}

TranslationActionPrimitive::TranslationActionPrimitive
    (const TranslationActionPrimitive & rhs)
    : _name(rhs._name)
    , _transVector(rhs._transVector)
{
}

TranslationActionPrimitive & TranslationActionPrimitive::operator=
    (const TranslationActionPrimitive & rhs)
{
    _name = rhs._name;

}

TranslationActionPrimitive::~TranslationActionPrimitive()
{
}

const Vector3 & TranslationActionPrimitive::getTransVector() const
{
    return _transVector;
}

void TranslationActionPrimitive::setTransVector(const Vector3 & transVector)
{
    _transVector = transVector;
}

DOMElement* TranslationActionPrimitive::toXML(const DOMDocument& doc, const DOMElement& parent) const
{
    DOMElement* element = ActionPrimitive::createElement(doc);


}


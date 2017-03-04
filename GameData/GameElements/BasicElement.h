//
// Created by wysockipatryk on 2/25/17.
//

#ifndef STRATEGYGAME_BASICELEMENT_H
#define STRATEGYGAME_BASICELEMENT_H

#include <string>
#include "json/json.hpp"

using json = nlohmann::json;

namespace BaseModel {
	class BasicElement {
	protected:
		std::string templateName;
		std::string templateType;
		std::string module;

	protected:

		BasicElement();

		BasicElement(json j);

	public:
		virtual const std::string &getTemplateName() const;

		virtual void setTemplateName(const std::string &templateName);

		virtual const std::string &getTemplateType() const;

		virtual void setTemplateType(const std::string &templateType);

		virtual const std::string &getModule() const;

		virtual void setModule(const std::string &module);

		virtual json serializeToJson();
	};
}

#endif //STRATEGYGAME_BASICELEMENT_H

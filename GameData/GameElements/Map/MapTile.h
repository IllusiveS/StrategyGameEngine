//
// Created by wysockipatryk on 2/17/17.
//

#ifndef STRATEGYGAME_MAPTILE_H
#define STRATEGYGAME_MAPTILE_H

#include <string>
#include <GameElements/BasicElement.h>
#include "json/json.hpp"

using json = nlohmann::json;

namespace BaseModel {
	class MapTile : public BasicElement {
	protected:
		int baseMovementCost;

	protected:
		std::string isPassableFunctionTemplateName;
		std::string isEnterableFunctionTemplateName;
		std::string isAttackableFunctionTemplateName;
		std::string retrieveMovementCostFunctionTemplateName;
		std::string textureName;

	public:
		const std::string &getTextureName() const;
		void setTextureName(const std::string &textureName);

		const std::string &getIsPassableFunctionTemplateName() const;
		void setIsPassableFunctionTemplateName(const std::string &isPassableFunction);

		const std::string &getIsEnterableFunctionTemplateName() const;
		void setIsEnterableFunctionTemplateName(const std::string &isEnterableFunction);

		const std::string &getIsAttackableFunctionTemplateName() const;
		void setIsAttackableFunctionTemplateName(const std::string &isAttackableFunction);

		const std::string &getTemplateName() const override;
		void setTemplateName(const std::string &templateName) override;

		const std::string &getTemplateType() const override;
		void setTemplateType(const std::string &templateType) override;

		const std::string &getModule() const override;
		void setModule(const std::string &module) override;

		const std::string &getRetrieveMovementCostFunctionTemplateName() const;
		void setRetrieveMovementCostFunctionTemplateName(const std::string &retrieveMovementCostFunctionTemplateName);

		int getBaseMovementCost() const;
		void setBaseMovementCost(int baseMovementCost);

		json serializeToJson() override;

	public:
		static MapTile *CreateUnitFromJson(json j);//TODO odczytywanie z JSONa
		MapTile();//TODO może jakiś konstruktor z parametrami?);
	};
}

#endif //STRATEGYGAME_MAPTILE_H

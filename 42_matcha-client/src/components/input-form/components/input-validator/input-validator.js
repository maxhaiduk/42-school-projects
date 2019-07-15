import getDynamicValidator from './validators/validator-getter';
import { StringHelper } from '~/helpers';

class InputValidator {

    /**
     * @param inputName
     * @param {array} inputFieldsState
     */
    constructor(inputName, inputFieldsState) {
        this.inputName = inputName;
        this.inputFieldsState = inputFieldsState;
    }

    /**
     * @param {string} value
     * @param {array} rules
     * @return {object}
     */
    validate(value, rules) {
        let result = {valid: false};

        for (let i = 0; i < rules.length; i++) {
            result = typeof rules[i] === 'object' ?
                        this.validateObject(rules[i], value) :
                        this.executeValidation(rules[i], value);

            if (!result.valid) {
                break;
            }
        }

        return result;
    }

    /**
     * Validates value with rules, that given as object and have payload
     *
     * @param {object} rules
     * @param {string} value
     * @return {*}
     */
    validateObject(rules, value) {
        let result;
        let rule;

        for (rule in rules) {
            if (!rules.hasOwnProperty(rule)) {
                continue;
            }

            result = this.executeValidation(rule, value, rules[rule]);

            if (!result.valid) {
                break;
            }
        }

        return result;
    }

    /**
     * @param {string} rule
     * @param {string} value
     * @param payload
     */
    executeValidation(rule, value, payload = null) {
        try {
            const validator = this.getValidator(rule);

            return validator.validate(value, payload);
        } catch (error) {
            console.error(error);
            console.error(`Check the syntax of '${rule}' validator`);
        }
    }

    /**
     * @param {string} rule
     * @return {AbstractValidator}
     */
    getValidator(rule) {
        const validatorName = `${StringHelper.ucFirst(rule)}Validator`;
        const validator = getDynamicValidator(validatorName);

        return new validator(this.inputName, this.inputFieldsState);
    }
}

export default InputValidator;


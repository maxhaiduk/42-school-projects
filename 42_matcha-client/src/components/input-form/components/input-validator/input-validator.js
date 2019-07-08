import getDynamicValidator from './validators/validator-getter';


class InputValidator {

    /**
     * @param {string} value
     * @param {array} rules
     * @return {boolean}
     */
    validate(value, rules) {

        let result = false;

        for (let i = 0; i < rules.length; i++) {

            console.log(rules[i]);

            result = typeof rules[i] === 'object' ?
                        this.validateObject(rules[i], value) :
                        this.executeValidation(rules[i], value);

            if (!result) {
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

        for (let rule in rules) {
            if (!rules.hasOwnProperty(rule)) {
                continue;
            }

            result = this.executeValidation(rule, value, rules[rule]);

            if (!result) {
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
        const validatorName = `${this.ucFirst(rule)}Validator`
        const validator = getDynamicValidator(validatorName)

        return new validator();
    }

    /**
     * Capitalises string
     *
     * @param {string} string
     * @return {string}
     */
    ucFirst(string) {
        return string.charAt(0).toUpperCase() + string.slice(1);
    }
}

export default InputValidator;


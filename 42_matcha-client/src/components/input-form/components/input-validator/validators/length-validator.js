import AbstractValidator from './abstract-validator';

export default class LengthValidator extends AbstractValidator {

    validate(value, payload) {

        let validationMethod;
        let result;
        let rules = payload;

        for (let rule in rules) {
            if (!rules.hasOwnProperty(rule)) {
                continue;
            }

            validationMethod = this.getMethod(rule);
            result = validationMethod(value, rules[rule]);

            if (!result) {
                break;
            }
        }

        return result;
    }

    /**
     * @param {string} value
     * @param {number} constraint
     * @return {boolean}
     */
    max(value, constraint) {
        return value.length <= constraint;
    }

    /**
     * @param value
     * @param constraint
     * @return {boolean}
     */
    min(value, constraint) {
        return value.length >= constraint;
    }
}
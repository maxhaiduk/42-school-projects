import AbstractValidator from './abstract-validator';

export default class LengthValidator extends AbstractValidator {

    /**
     * @inheritDoc
     */
    validate(value, payload) {

        let validationMethod;
        let valid;
        let rules = payload;
        let rule;

        for (rule in rules) {
            if (!rules.hasOwnProperty(rule)) {
                continue;
            }

            validationMethod = this.getMethod(rule);
            valid = validationMethod(value, rules[rule]);

            if (!valid) {
                break;
            }
        }

        return {
            valid,
            ...(!valid && { errorMessage: this.getErrorMessage({
                    rule,
                    value: rules[rule]
                }) })
        }
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

    getErrorMessage(payload) {

        let map = {
            max: 'greater',
            min: 'less',
        };

        return 'The {name} shouldn`t be {criteria} {value} characters'
            .replace('{name}', this.inputName)
            .replace('{criteria}', map[payload.rule])
            .replace('{value}', payload.value);
    }
}
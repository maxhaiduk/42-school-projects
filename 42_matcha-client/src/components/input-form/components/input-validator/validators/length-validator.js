import AbstractValidator from './abstract-validator';
import { StringHelper } from '~/helpers';

/**
 * Validates given string for length
 * The min and max value can be specify in form configuration
 *
 * example:
 *  length: {
 *      max: 12,
 *      min: 4,
 *  }
 *
 *  both rules are optional
 */
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

        if (valid === undefined || rules.length === 0) {
            throw new Error('No rules were specified for length validator');
        }

        return {
            valid,
            ...(!valid && { message: this.getMessage({
                    rule,
                    value: rules[rule]
                })
            })
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

    getMessage(payload) {

        let map = {
            max: 'greater',
            min: 'less',
        };

        return 'The {name} shouldn`t be {criteria} {value} characters'
            .replace('{name}', StringHelper.ucFirst(this.inputName))
            .replace('{criteria}', map[payload.rule])
            .replace('{value}', payload.value);
    }
}
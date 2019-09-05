import AbstractValidator from './abstract-validator';
import { StringHelper } from '~/helpers';

export default class RegexpValidator extends AbstractValidator {

  rules = {
    hasLowerAlpha: {
      pattern: '[a-z]',
      message: '{name} must contain at least one lowercase character',
    },
    hasUpperAlpha: {
      pattern: '[A-Z]',
      message: '{name} must contain at least one capital character',
    },
    hasNumber: {
      pattern: '[0-9]',
      message: '{name} must contain at least one number',
    },
    email: {
      pattern: '^.+@[a-z]+(\.[a-z]+)+$',
      message: 'Incorrect email',
    },
  };

  /**
   * @inheritDoc
   */
  validate(value, payload) {

    let valid = false;
    let rule;

    let rules = this.fetchRules(this.getRules());

    for (rule of Object.values(rules)) {
      let regexp = new RegExp(rule.pattern);
      valid = regexp.test(value);
      if (!valid) {
        break;
      }
    }

    return {
      valid,
      ...(!valid && {
        message: this.getMessage({
          description: rule.message
        })
      })
    }
  }

  /**
   * @inheritDoc
   */
  getMessage({description}) {

    return description.replace(
      '{name}',
      StringHelper.toHumanCaseCap(this.inputName)
    )
  }

  /**
   * Filters rules of regexp validator with current validator rules
   *
   * @param {string[]} validatorRules
   * @returns {Object}
   */
  fetchRules(validatorRules) {
    return validatorRules
      .map(rule => {
        if (rule in this.rules) {
          return rule;
        }
        throw new Error(`${rule} is wrong rule`);
      })
      .reduce((obj, rule) => {
        obj[rule] = this.rules[rule];
        return obj;
      }, {});
  }
}
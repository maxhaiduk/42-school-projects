import RegexpValidator from './regexp-validator';

export default class PasswordValidator extends RegexpValidator {

  getRules() {
    return [
      'hasLowerAlpha',
      'hasUpperAlpha',
      'hasDigit',
    ]
  }
}
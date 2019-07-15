import RegexpValidator from './regexp-validator';

export default class PasswordValidator extends RegexpValidator {

    getPatterns() {
        return this.fetchPatterns([
            '[a-z]', '[0-9]', '[A-Z]'
        ])
    }
}
import RegexpValidator from './regexp-validator';

export default class EmailValidator extends RegexpValidator {

    getPatterns() {
        return this.fetchPatterns([
            '^.+@[a-z]+(\.[a-z]+)+$'
        ])
    }
}
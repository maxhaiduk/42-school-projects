import RegexpValidator from './regexp-validator';

export default class EmailValidator extends RegexpValidator {
    getRules() {
        return [
            'email',
        ];
    }
}
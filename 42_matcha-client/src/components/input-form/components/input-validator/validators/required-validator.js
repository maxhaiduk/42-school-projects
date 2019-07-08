import AbstractValidator from './abstract-validator';

export default class RequiredValidator extends AbstractValidator {
    validate(value, payload) {
        return (value !== undefined && value.length !== 0);
    }
}
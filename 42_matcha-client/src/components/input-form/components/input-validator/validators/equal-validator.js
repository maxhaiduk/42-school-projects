import AbstractValidator from './abstract-validator';

export default class EqualValidator extends AbstractValidator {

    constructor(inputFieldsState) {
        super();
        this.inputFieldsState = inputFieldsState;
    }

    validate(value, payload) {
        let equalToValue = (this.inputFieldsState[payload] || {}).value;

        if (equalToValue === undefined) {
            throw new Error(`Field ${payload} doesn't exists`);
        }

        return value === equalToValue;
    }
}
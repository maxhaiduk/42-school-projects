import AbstractValidator from './abstract-validator';
import {StringHelper} from "~/helpers";

export default class EqualValidator extends AbstractValidator {

    /**
     * @inheritDoc
     */
    validate(value, payload) {
        let equalToValue = (this.inputFieldsState[payload] || {}).value;

        if (equalToValue === undefined) {
            throw new Error(`Field ${payload} doesn't exists`);
        }

        let valid = value === equalToValue;

        return {
            valid,
            ...(!valid && { errorMessage: this.getErrorMessage(payload) })
        }
    }

    /**
     * @inheritDoc
     */
    getErrorMessage(payload) {

        return 'This field must be equal to {equalTo}'
            .replace('{equalTo}', StringHelper.ucFirst(payload));
    }
}
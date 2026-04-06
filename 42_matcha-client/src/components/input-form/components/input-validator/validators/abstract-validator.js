export default class AbstractValidator {

    /**
     * @param {string} inputName
     * @param {object} inputFieldsState
     */
    constructor(inputName, inputFieldsState = []) {
        this.inputName = inputName;
        this.inputFieldsState = inputFieldsState;
    }

    /**
     * @param {string} value
     * @param {*} payload
     * @return {object} result of validation with error message
     *  {
     *      valid,
     *      message
     *  }
     */
    validate(value, payload) {
        throw new Error("Method 'validate' was not implemented");

        return {};
    }

    /**
     * @param {*} payload
     * @return {string} error message
     */
    getMessage(payload) {
        throw new Error("Method 'getMessage' was not implemented");
    }


    /**
     * @param {string} methodName
     * @param {function} transform callback for method name transformation
     *  if it is not equal with name specified in rules
     *
     * @return {function} validation method
     */
    getMethod(methodName, transform = null) {
        if (typeof transform === 'function') {
            methodName = transform(methodName);
        }

        if (this[methodName] === undefined) {
            throw new Error(`Method ${methodName} was not found in ` +
                this.constructor.name);
        }

        return this[methodName];
    }
}
export default class AbstractValidator {
    validate(value, payload) {
        throw new Error("Method 'validate' was not implemented");
    }

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
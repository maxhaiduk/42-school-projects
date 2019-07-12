export default class StringHelper {

    /**
     * Capitalises firs character of the string
     *
     * @param {string} string
     * @return {string}
     */
    static ucFirst(string) {
        return string.charAt(0).toUpperCase() + string.slice(1);
    }
}
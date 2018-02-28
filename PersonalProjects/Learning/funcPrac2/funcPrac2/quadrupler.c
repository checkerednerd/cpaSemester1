/*Ron Vincent
*2018-02-28
*quadruples a supplied value
*/


static int quadrupler(int val) { //declared static to avoid linker errors, gives function global scope, namespace scope, and class scope
	int result;

	result = (val * 4);
	return result;
}
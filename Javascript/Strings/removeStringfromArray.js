// Return a new array with the strings filtered out
function filter_list(l) {
  const arrayWithoutStr = l.filter(val => typeof val != "string" );
  return arrayWithoutStr;
}
//console.log(filter_list(["string1", 30, "string2", true]));
//returns: Array [30,true]
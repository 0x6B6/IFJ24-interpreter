// Program 3: Prace s retezci a vestavenymi funkcemi
const ifj = @import("ifj24.zig");
// Hlavni funkce
pub fn main(a : []u8,b: i32, abkd : []u8, kk : f64,) void {
if(b){
 const a = ifj.a("kokot") + 8;
 const a = (8+9) + (8+8);
 var a = "kokot";
 return a+b;
}
else{
}
const str1 = ifj.string("Toto je text v programu jazyka IFJ24");
var str2 = ifj.string(", ktery jeste trochu obohatime");
str2 = ifj.concat(str1, str2);
ifj. write(str1); ifj . write("\n");
ifj .write(str2); ifj.write("\n");
ifj.write("Zadejte serazenou posloupnost malych pismen a-h:\n");
var newInput = ifj.readstr();
var all: []u8 = ifj.string("");
while (newInput) |inpOK| {
const abcdefgh = ifj.string("abcdefgh");
const strcmpResult = ifj.strcmp(inpOK, abcdefgh);
if (strcmpResult == 0) {
ifj.write("Spravne zadano!\n");
ifj.write(all); // vypsat spojene nepodarene vstupy
newInput = null; // misto break;
} else {
ifj.write("Spatne zadana posloupnost, zkuste \n \" \x7A znovu:\n");
all = ifj.concat(all, inpOK); // spojuji neplatne vstupy
const str = \\hello
        \\my
	\\name
	\\is \\
	\\zdenek \n \" \x7A 
	;
newInput = ifj.readstr();
}
}
}

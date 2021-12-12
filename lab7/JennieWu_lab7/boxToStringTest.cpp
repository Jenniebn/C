#include "shapes.h"
#include "shapeFuncs.h"
#include "tddFuncs.h"




int main() {

    struct Box b1,b2;
    // SAMPLE FORMAT: [ul=(3.4,-5),w=5,h=7] (without the []s)
    initBox(&b1,3.0,4.0,5.0,6.0);  
    assertEquals("ul=(3,4),w=5,h=6", boxToString(b1), "boxToString(b1)");

    initBox(&b2,3.14159,6.2831853071,2.343434,5.12345);
    assertEquals("ul=(3.14,6.28),w=2.34,h=5.12", boxToString(b2), "pointToString(b2)");
    assertEquals("ul=(3,6),w=2,h=5", boxToString(b2,1), "pointToString(b2,1)");
    assertEquals("ul=(3.142,6.283),w=2.343,h=5.123", boxToString(b2,4), "pointToString(b2,4)");
    assertEquals("ul=(3.1416,6.2832),w=2.3434,h=5.1235", boxToString(b2,5), "pointToString(b2,5)");

		   
    return 0;
}

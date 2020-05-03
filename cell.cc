
#include "cell.h"


Cell:: Cell (int r, int c): r{r}, c{c} {
}
// get the link locate in the cell
Link* Cell:: getContain(){
    return contain;
}
// set the link in the cell
void Cell:: setContain(Link* lk){
    contain = lk;
}



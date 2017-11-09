#include "Checkout.h"
#include "DessertItem.h"
#include "IceCream.h"
#include "cookie.h"
#include "sundae.h"
#include "candy.h"

void main ( )
{
	Checkout checkout;
	checkout.enterItem ( new Candy ( "Peanut Butter" , 2.34 ,33 ) );
	checkout.enterItem ( new IceCream ( "Vanilla iceCream" , 105 ) );
	
	checkout.enterItem(new Sundae("Choc. Chip Ice Cream",145, "Hot Fudge" , 50)); 
	checkout.enterItem(new Cookie("Oatmeal Raisin Cookies", 4, 399)); 
	cout << checkout;
	
	checkout.clear ( );
	cout << checkout;

	checkout.enterItem(new IceCream("Strawberry Ice Cream",145)); 
	checkout.enterItem(new Sundae("Vanilla Ice Cream",105, "Caramel", 50)); 
	checkout.enterItem(new Candy("Gummy Worms", 1.33, 89)); 
	checkout.enterItem(new Cookie("Chocolate Chip Cookies", 4, 399)); 
	checkout.enterItem(new Candy("Salt Water Taffy", 1.5, 209)); 
	checkout.enterItem(new Candy("Candy Corn",3.0, 109)); 
     
	cout<<"\nNumber of items: " << checkout.numberOfItems() << "\n"; 
	cout<<"\nTotal tax: " << checkout.totalTax() << "\n"; 
	cout<<"\nCost + Tax: " << checkout.totalCost() << checkout.totalTax() << "\n"; 
	cout<<checkout; 
    
}
/* Ciara Routly */

/* This program acts as a food bank that keeps a record of requests and 
donations that come in */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
int option, don_quant, req_quant, found, flag;
int don_amt[100];
int i, req_count, don_count;
char req_inv_type[100][20], don_inv_type[100][20];
const char word [100], req_word[100];
int req_amt[100];

	
	// Prompt menu 
	printf("Welcome to the Food Bank Program\n\n\n");
	printf(" 1. Add a donation\n 2. Add a request\n 3. Fulfill a request\n");
	printf(" 4. Print status report\n 5. Exit\n\n");
	// Read in user's menu choice
	printf("Enter your choice: ");
	scanf ("%d",&option);
    
    /* Keep going until the user quits. */
    while (option != 5) {
          
          
          if (option == 1) {
         	
         	// Prompt user to enter the item name and quantity to donate
          	    printf("\nEnter inventory type: ");
                scanf ("%s", &word);  
                printf("Enter the amount: ");
				scanf ("%d", &don_quant);
				
	        // Test if item is already stored in donation array
                 found = -99;
                 for (i=0;i<don_count; i++)
                   {
                      if (strcmp(don_inv_type[i], word)==0)
                            found = i;
                   }
                 // If item is not found, copy item type and amount into array
                if (found == -99)
                    {
                       strcpy(don_inv_type[i],word);
                      don_amt[i] = don_quant;
                      don_count ++;
                      
                    } 
                else {
                // If item was found, increase item donation quantity
                   don_amt[found] += don_quant;
           }	
               {
                   printf("\nDonation added!\n");   
                   system("pause");
                   printf("\n");
                } 
             }
    
          
    	  else if (option == 2) {
               // Prompt user to enter the item name and quantity to request
               printf("\nEnter inventory type: ");
                scanf ("%s", &req_word);  
                printf("Enter the amount: ");
				scanf ("%d", &req_quant);
				
	           // Test if item is already stored in the array
                 found = -99;
                 for (i=0;i<req_count; i++)
                   {
                      if (strcmp(req_inv_type[i],req_word)==0)
                            found = i;
                   }
    	      // If item is not stored in array, copy item type into array
                if (found == -99)
                    {
                       strcpy(req_inv_type[i],req_word);
                      req_amt[i] = req_quant;
                      // Increase request amount by 1 each time through
                      req_count ++;
                    
                    } 
                else {
                // If item was found in array, add request quantity 
                   req_amt[found] += req_quant;
                   
                } 
                {
                 printf("\nRequest added!\n");   
                 system("pause");
                 printf("\n");
 	            }	
              
             }
         
         
          else if (option == 3) {
          	
          	printf("\n\n-------- Fulfilling Requests --------\n\n");
          	
			    
                if (req_count == 0)
				{
				printf("No requests have been made.\n\n");
 						}
	else if (don_count == 0)
		 {
    	  printf("Cannot be fulfilled. No donations have been made.\n\n");
         }
		 else
           {   // request does not find a match in donations
             found = -99;
             printf("No donations of requested item have been made.");
             for (i=0; i<don_count; i++)
                {
                  if ( strcmp(don_inv_type[i],req_inv_type[0]) == 0)
                  
                      found = i;
                }
             if (found == -99){
             
                
             }else
                { 
				//Tests to see if request is ==donations, or exceeds, or is less
                  if (don_amt[found]==req_amt[0])
                     {
                        printf("Request fulfilled.\n\n");
                   //delete request by moving all the others up by one position
                        for (i=1;i<req_count;i++)
                          {
                          	//copy the lower value into a higher position
                             strcpy(req_inv_type[i-1], req_inv_type[i]);    
                             req_amt[i-1] = req_amt[i];
                          }
                        //we just lost an entry, so lower the counter
                        req_count -- ;
                        for (i=found;i<don_count - 1;i++)
                          {
                             strcpy(don_inv_type[i], don_inv_type[i+1]);
                             don_amt[i]= don_amt[i+1];
                          }
                        don_count -- ;
                      }
                    else if (don_amt[found]>req_amt[0])
                           {
                           	printf("Request fulfilled.\n\n");
                           	//reduce the donation table's amount;
                              don_amt[found] -= req_amt[0]; 
                            //remove the request as above
                              for (i=1;i<req_count;i++)
                                {
                                // copy the lower value into a higher position	
                                  strcpy(req_inv_type[i-1], req_inv_type[i]);
                                  req_amt[i-1] = req_amt[i];
                                }
                              req_count -- ;
                            }
                      else { // need to  remove donation and reduce request
                      printf("Request partially fulfilled.\n\n");
                             req_amt[0] -= don_amt[found];
                             for (i=found;i<don_count - 1;i++)
                               {
                                  strcpy(don_inv_type[i], don_inv_type[i+1]);
                                  don_amt[i]= don_amt[i+1];
                               }
                             don_count -- ;
                           }
	   	        		   }
  					       }
             }
             
         else if (option == 4){
         	
         	{
         	// Prints a list of item name(s) and amount(s) currently in stock
         	printf("\nPrinting the Donations Table...\n\n");
         	
         	for(i=1;i<don_count;i++){
         	
         	
         	printf("%s %d\n\n", don_inv_type[i],don_amt[i]);
         }
     }
         
         {
          	// Prints a list of item name(s) and amount(s) currently requested
         	printf("\nPrinting the Requests Table...\n\n");
         	
         	for(i=0;i<req_count;i++){
         	
         	printf("%s %d\n\n", req_inv_type[i],req_amt[i]);
         }
     }
         
         }
         
         
          
   	  	       // Will print if user enters an incorrect menu value 
          else if (option != 5) {
               	  printf("Sorry, that was invalid.\n\n");
             }
          
    	  	    // Reprompt the menu.
         		 	printf("\n\nWelcome to the Food Bank Program\n\n\n");
					printf(" 1. Add a donation\n 2. Add a request\n 3. Fulfill a request\n");
					printf(" 4. Print status report\n 5. Exit\n\n");
	
					printf("Enter your choice: ");
					scanf ("%d",&option);
             } 			
			 
			 // end while
			 
			 if (option ==5){
			 	printf("\n\nThank you for using the software. Bye for now. \n\n");
			 }
          
    system("PAUSE");
    return 0;
}


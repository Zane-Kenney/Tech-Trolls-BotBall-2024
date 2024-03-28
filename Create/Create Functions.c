int main()
{
    create_connect();
    create_drive_direct(-nspeed,-nspeed);
    msleep(1000);     //drive past start box tape
    stopline();
    left90(); //get to line between 3 and 5, turn 
    create_drive_direct(nspeed,nspeed);
    msleep(4000);
    
    
    
    create_disconnect();
    return 0;
}

void left90 ()
{
    set_create_total_angle(0);
    while (abs(get_create_total_angle() ) < leftN) // while create has turned less than 90 degrees, turn left
    	{
        create_drive_direct(-tspeed,tspeed);
        msleep(10);
    	}
}

void right90 ()
	{
	while (abs(get_create_total_angle() ) < rightN) // while create has turned less than 90 degrees, turn right
    	{
        create_drive_direct(tspeed,-tspeed);
        msleep(10);
    	}
	}

void flip ()
	{
	set_create_total_angle(0);
    while(abs(get_create_total_angle()) <flipN ) // while create has turned less than 180 degrees, spin CCW.
    	{
    	create_drive_direct(-tspeed,tspeed);
        msleep(10);
    	}
	}

void square ()
	{
	while( (get_create_lbump() == 0 ) || (get_create_rbump() == 0 ) ) //while either front bumper isn't pressed, enter loop.
    	{
    	if ((get_create_lbump() == 0 ) && (get_create_rbump() == 0 ))   //if neither bumper is pressed, go foward.
        	{
            create_drive_direct(nspeed,nspeed);
        	msleep(10);
			}
        if ((get_create_lbump() == 1 ) && (get_create_rbump() == 0 )) //if only left is pressed, move with right motor.
        	{
        	create_drive_direct(0,nspeed);
        	}
        if ((get_create_lbump() == 0 ) && (get_create_rbump() == 1 )) //if only right is pressed, move with left motor foward.
        	{
        	create_drive_direct(nspeed,0);
            msleep(10);
        	}
		}
	}

void stopline() 
	{
	  while ((get_create_lcliff_amt() > tape)  ||  (get_create_rcliff_amt() > tape) )     //as long as one of the side sensors doesn't hit black
    	{
    	if ((get_create_lcliff_amt() > tape)  &&  (get_create_rcliff_amt() > tape))       //neither see tape, go foward
        	{
        	create_drive_direct(nspeed,nspeed);
            msleep(10);
        	}
        else if ((get_create_lcliff_amt() < tape)  &&  (get_create_rcliff_amt() > tape)) //if only left sensor reads, move with right foward
        	{
        	create_drive_direct(0,nspeed);
            msleep(10);
        	}
        else if ((get_create_lcliff_amt() > tape)  &&  (get_create_rcliff_amt() < tape)) //if only right sensor reads, move with left foward
        	{
        	create_drive_direct(nspeed,0);
            msleep(10);
        	}
    	}
	}
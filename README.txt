Folder Structure

1)main simulation/
    main.c            #main function to run this simulation program and print results
    event_list.h       #definition for event and opration of priority queue
    event_list.c       #implementation of functions for priotity queue(event list)
    part_queue.h       #definition for part and opration of FIFO queue 
    part_queue.c       #implementation of functions for FIFO queue
    
    random_number.h   #definition for a function which generates an exponatially distributed random number

    random_number.c     #implementation of the function above
    event_handler.h     #definition for event handler functions
    event_handler.h     #implementation for the fucn
    simulation_engine.h  #definition for general operation of eventlist and FIFO queue
    simulation_engine.c  #implementation for functions above
    

2)arrival rate and time/
    Time vs arrival rate.txt  #store the data for use
    rate_time.c  #run this simulation with different arrival rate
    event_list.h
    event_list.c
    part_queue.h
    part_queue.c
    random_number.h
    random_number.c
    event_handler.h
    event_handler.c
    simulation_engine.h
    simulation_engine.c

3)queue_with_N_events/
    N_and_time_data.txt   #store the results of average operation     time for N events
    queue_with_N_events.c  #run this simulation and print the results

4)single_queue/
    single_queue.txt     #store the data for literature analysis
    single_queue.c       #simulate the operation of a single queue
    event_list.h
    event_list.c
    part_queue.h
    part_queue.c
    random_number.h
    random_number.c



Run in jinx
1.qsub -I -q class -l nodes=1 -l walltime=00:05:00

2.Set directory to certain folder and compile all source code by following command
gcc *.c -std=c99 -o myprog -lm 

3./myprog

4.exit

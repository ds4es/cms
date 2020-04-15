void cout_message(const std::string&msg){
	std::cout << msg << std::endl;
}

void press_enter_to_continue() 
{ 
  std::cout<<"Press [Enter] to continue...";
  std::cin.ignore();
} 

std::string microseconds_to_readable_time_cout(long long microseconds_time) 
{ 
    long long microseconds = (long long) (microseconds_time) % 1000 ;
    long long milliseconds = (long long) (microseconds_time / 1000) % 1000 ;
    long long seconds = (long long) (microseconds_time / 1000000) % 60 ;
    long long minutes = (long long) ((microseconds_time / (1000000*60)) % 60);
    // long long hours   = (long long) ((duree_en_microsec / (1000000*60*60)) % 24);

	return std::to_string(minutes) + " min " + std::to_string(seconds) + " sec " + std::to_string(milliseconds) + " msec " + std::to_string(microseconds) + " µs";
}
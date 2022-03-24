# Secu-compagnon
## NOTE
THE VIRUS WORKS ONLY ON AN LINUX SYSTEM
## Testing the virus ( infection ) 
copy the directory called "dumptz" :

- cp -r dumptz <name>
  
compile "MediaPlayer.c" in this new directory :
  
- gcc -o MediaPlayer MediaPlayer.c $(pkg-config --cflags --libs gtk+-3.0)
  
exec it :
  
- ./MediaPlayer

In order to see if the infected files works properly :
  
- cp ../pgs/<exec_you_want_to_copy> <name_you_want_to_give_him> 
  
### BE CAREFUL GIVE A NAME DIFFERENT FROM THE EXECUTABLES ALREADY IN THE FOLDER
- ./<any_infected_program>

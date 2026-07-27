#include <iostream>
#include "playlist_ll.h"

int main(){
    CircularList<std::string>* head = new CircularList<std::string>();
    CircularList<std::string>* second = new CircularList<std::string>();
    CircularList<std::string>* third = new CircularList<std::string>();
    CircularList<std::string>* songPlaying = head;

    head->data = "Song A";
    second->data = "Song B";
    third-> data = "Song C";

    head->next = second;
    second->next = third;
    third->next = head;
    
    head->prev = third;
    second->prev = head;
    third->prev = second;

    // Testing play_All
    std::cout<<"Playlist: "<< std::endl;
    play_All(head);
    
    //Testing insert_Head
    std::cout<<"New song added at head."<<std::endl;
    insert_Head(std::string("Song D"), &head);
    std::cout<<"Playlist: "<< std::endl;
    play_All(head);

    //Testing insert_End
    std::cout<<"New song added at end."<<std::endl;
    insert_End(std::string("Song E"), head);
    std::cout<<"Playlist: "<<std::endl;
    play_All(head);

    //Testing display_Current, next_Song and prev_Song
    std::cout<<"Current Song Playing: ";
    display_Current(songPlaying);
    next_Song(&songPlaying);

    std::cout<<"Current Song Playing: ";
    display_Current(songPlaying);
    prev_Song(&songPlaying);

    std::cout<<"Current Song Playing: ";
    display_Current(songPlaying);
    
    destroy_List(&head);
    play_All(head);
    std::cout<<"Playlist destroyed."<<std::endl;

    return 0;
}

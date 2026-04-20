/*
 * File: playlist.c
 * Description: Includes the code/logic for functions of playlist.h
 */
#include "../include/playlist.h"

/**
 * @brief Initialize a new playlist
 *
 * @param p_playlist pointer the playlist
 */
void init_playlist(Playlist *p_playlist)
{
    p_playlist->p_head = NULL;
    p_playlist->size = 0;
}

/**
 * @brief add a new song to the end of the playlist
 *
 * @param playlist pointer to playlist
 * @param title    title of the new song
 * @param artist   artist of the new song
 */
void add_song(Playlist *playlist, const char *title, const char *artist)
{
    if (playlist->size >= MAX_SONGS)
    {
        printf("Warning: Playlist reached maximum size (%d songs). New song discarded.\n", MAX_SONGS);
        return;
    }

    Song *newSong = malloc(sizeof(*newSong));
    if (!newSong)
        return;

    newSong->title = malloc(strlen(title) + 1);
    newSong->artist = malloc(strlen(artist) + 1);

    if (!newSong->title || !newSong->artist)
    {
        free(newSong->title);
        free(newSong->artist);
        free(newSong);
        return;
    }

    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->p_nextSong = NULL;

    if (!playlist->p_head)
    {
        playlist->p_head = newSong;
    }
    else
    {
        Song *last = playlist->p_head;
        while (last->p_nextSong)
            last = last->p_nextSong;
        last->p_nextSong = newSong;
    }

    playlist->size++;
}

/**
 * @brief print out all songs of the playlist
 *
 * @param playlist pointer to playlist
 */
void print_playlist(const Playlist *playlist)
{
    printf("Playlist contains %d song(s):\n", playlist->size);
    Song *current = playlist->p_head;
    while (current)
    {
        printf("Title: %s, Artist: %s\n", current->title, current->artist);
        current = current->p_nextSong;
    }
}

/**
 * @brief delete the first song of the playlist
 *
 * @param playlist pointer to playlist
 */
void delete_firstSong(Playlist *playlist)
{
    if (!playlist->p_head)
        return;

    Song *tmp = playlist->p_head;
    playlist->p_head = tmp->p_nextSong;

    free(tmp->title);
    free(tmp->artist);
    free(tmp);

    playlist->size--;
}

/**
 * @brief delete playlist and free up memory
 *
 * @param playlist pointer to playlist
 */
void delete_playlist(Playlist *playlist)
{
    while (playlist->p_head)
        delete_firstSong(playlist);
}




/**
 * @brief find a song by its title
 *
 * 
 * Use a linear search and strcmp for string comparison.
 * Return a pointer to the found Song.
 * Return NULL if the song is not found.
 * 
 * @param playlist pointer to playlist
 * @param title    title of the song to find
 * @return pointer to the found song, or NULL if not found
 */
Song* find_song_by_title(Playlist *playlist, const char *title)
{
    Song *current = playlist->p_head;
    while (current)
    {
        if (strcmp(current->title, title) == 0)
            return current;
        current = current->p_nextSong;
    }
    return NULL; /* song not found */
}

int count_songs_recursive(const Song *current);
/**
 * @brief count the number of songs in the playlist using recursion 
 * 
 * Use a helper function that takes a pointer to the current Song as an argument.
 * The helper function should return 1 + the count of the rest of the list, or 0 if the current song is NULL.
 * The main function should call the helper function with the head of the playlist.
 */
int count_songs_recursive(const Song *current) // helper function for recursion
{
    if (!current) // base case: if current song is NULL, return 0
        return 0;
    return count_songs_recursive(current->p_nextSong) + 1; // recursive call with the next song
}

int count_songs(const Playlist *playlist) // main function to count songs using recursion
{
    return count_songs_recursive(playlist->p_head); // start recursion with the head of the playlist
}

/**
 * @brief sort the playlist by song title in alphabetical order
 * 
 * @param playlist pointer to playlist
 * @return void
 */
void sort_playlist_by_title(Playlist *playlist);
{
    if (!playlist->p_head || !playlist->p_head->p_nextSong) // if playlist is empty or has only one song, it's already sorted
        return;

    /**
     * or:
     * int lenght = count_songs_recursive(playlist -> p_head)
     * if (lenght==1 || lenght==0)
     *      return;
     */

    int swapped;
    do { 
        swapped = 0
        Song *current = playlist->p_head;
        while (current->p_nextSong) {

}
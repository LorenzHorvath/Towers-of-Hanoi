/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 09
 * Title:			Tower of Hanoi Disk ADT implementation
 * Author:			Lorenz Horvath
 * ----------------------------------------------------------
 * Description:
 * Implementation of toh_board.h.
 * ----------------------------------------------------------
 */

/* Includes, definitions and instanciations */
#include <stdbool.h>
#include "toh_board.h"

/* ========================================================= */
/* Private functions                                         */

/**
 * Moves a single disk from the top of the 'source' rod to the 'target' rod.
 * The move shall only be performed if it is allowed.
 * 
 * @param source The rod from which the disk shall be moved.
 * @param target The rod to which the disk shall be moved.
 * @return True if the move was successful and according to the rules, false otherwise.
 */
static bool ts_move_disk(RodName source, RodName target) {
    return 0;
}

/**
 * Moves a stack of disks of the given size form the 'source' rod to the 'target' rod 
 * using the 'intermediate' rod as intermediate disk buffer. 
 * The move shall only be performed if it is valid. The move is valid, if each 
 * move of affected disks is allowed.
 * 
 * @param size  The size of the disk stack to move.
 * @param source The rod from which the disks shall be moved.
 * @param intermediate The rod that serves as intermediate buffer for the disks.
 * @param target The rod to which the disks shall be moved.
 * @return True if the move was successful and according to the rules, false otherwise.
 */
static bool ts_move_stack(unsigned short size, RodName source, RodName intermediate, RodName target) {
    return 0;
}

/* ========================================================= */
/* Public functions                                         */

/**
 * Initials a 'Tower of Hanoi' board with the given number of disks.
 * To initialize the board, all reqired disks are placed on the left rod
 * in ascending order of their size, the smallest disk at the top. 
 * The middle and right rod are empty.
 * 
 * All disks are initialized accordingly.
 * 
 * @param disk_count The number of disks to use. Must be less than 'MAX_DISKS'.
 */
void ts_init(int disk_count)
{
    return 0;
}

/**
 * Solves the puzzle by moving all disks from the left rod to the right rod.
 * In fact, this is the only function needed to 'play' the game after the
 * board was initialized.
 * 
 */
void ts_solve()
{
    return 0;
}
/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 09
 * Title:			Tower of Hanoi Disk ADT
 * Author:			Lorenz Horvath
 * ----------------------------------------------------------
 * Description:
 * The declaration of an Abstract Data Type representing
 * a single disk of the Tower of Hanoi.
 * 
 * @see toh_solver.h for details regarding *Tower of Hanoi*.
 * ----------------------------------------------------------
 */


#include <stdbool.h>
/* == !Include guard and required includes need to be added */

/** Declares a disk. */
typedef struct DiskImpl* Disk;
/**
 * Provides the instance of the disk with the given size.
 * Valid disk sizes are from 1 to MAX_DISKS.
 * 
 * @param size The size of the desired disk.
 * @return The disk of the given size or 0, 
 *         if no such disk is available.
 */
Disk td_get_disk(unsigned short size);

/**
 * Determines whether or not the given disk is valid.
 * It is valid if it is not 0 and has a size between 1 and MAX_DISKS.
 * 
 * @param disk The disk in focus of this ADT.
 * @return True if the disk is valid, false otherwise.
 */
bool td_is_valid(Disk disk);

/**
 * Provides the size of the given disk.
 * 
 * @param disk The disk in focus of this ADT.
 * @return The size of the disk, if it is valid or 0 otherwise.
 */
unsigned short td_get_size(Disk disk);

/**
 * Compares the size of the candidate disk with size of the given disk.
 * 
 * @param disk The disk in focus of this ADT.
 * @param smaller_candidate The disk to evaluate.
 * @return True if the 'smaller_candidate' disk is smaller than the 
 * given disk of this ADT and both disks are valid, false otherwise.
 */
bool td_is_smaller(Disk disk, Disk small);


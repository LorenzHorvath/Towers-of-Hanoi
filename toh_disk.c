/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 09
 * Title:			Tower of Hanoi Disk ADT Implemenation
 * Author:			Lorenz Horvath
 * ----------------------------------------------------------
 * Description:
 * Implementation of toh_disk.h.
 * ----------------------------------------------------------
 */

#include "toh_disk.h"
#include "config.h"

struct DiskImpl
{
    unsigned short size;
};

struct DiskImpl disks[255];
int diskCounter = 0;

/**
 * Provides the instance of the disk with the given size.
 * Valid disk sizes are from 1 to MAX_DISKS.
 * 
 * @param size The size of the desired disk.
 * @return The disk of the given size or 0, 
 *         if no such disk is available.
 */
Disk td_get_disk(unsigned short size)
{
    if (0 < size && size <= MAX_DISKS)
    {
        if (diskCounter > 255)
        {
            diskCounter = 0;
        }
        disks[diskCounter].size = size;
        diskCounter++;
        return &disks[diskCounter - 1];
    }
    return 0;
}

/**
 * Determines whether or not the given disk is valid.
 * It is valid if it is not 0 and has a size between 1 and MAX_DISKS.
 * 
 * @param disk The disk in focus of this ADT.
 * @return True if the disk is valid, false otherwise.
 */
bool td_is_valid(Disk disk)
{
    if (disk != 0 && disk->size > 0 && disk->size <= MAX_DISKS)
    {
        return true;
    }
    return false;
}

/**
 * Provides the size of the given disk.
 * 
 * @param disk The disk in focus of this ADT.
 * @return The size of the disk, if it is valid or 0 otherwise.
 */
unsigned short td_get_size(Disk disk)
{
    if (td_is_valid(disk) == true)
    {
        if (disk->size != 0)
        {
            return disk->size;
        }
    }
    return 0;
}

/**
 * Compares the size of the candidate disk with size of the given disk.
 * 
 * @param disk The disk in focus of this ADT.
 * @param smaller_candidate The disk to evaluate.
 * @return True if the 'smaller_candidate' disk is smaller than the 
 * given disk of this ADT and both disks are valid, false otherwise.
 */
bool td_is_smaller(Disk disk, Disk small)
{
    if (td_is_valid(disk) == true && td_is_valid(small) == true)
    {
        if (td_get_size(disk) > td_get_size(small))
        {
            return true;
        }
    }
    return false;
}


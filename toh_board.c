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

#include "toh_board.h"

#include "config.h"
#include "toh_disk.h"

/** Abstraction of a rod type */
/* Hint: Define a type 'Rod' as a pointer to Disk 
   for usage in exchange with Disk array */
struct TohBoardImpl
{
   Disk leftRod[MAX_DISKS];
   Disk middleRod[MAX_DISKS];
   Disk rightRod[MAX_DISKS];
};

static struct TohBoardImpl board = {{0}, {0}, {0}};
/**
 * Provides the instance of the 'Tower of Hanoi' board.
 * Exactly one instance is supported.
 * 
 * @return TohBoard The board instance.
 */
TohBoard tb_get_board()
{
   return &board;
}

/**
 * Removes all disks from any rod of the given board.
 * 
 * @param board The board instance in focus.
 */
TohBoard tb_clear_board(TohBoard board)
{
   for (int i = 0; i < MAX_DISKS; i++)
   {
      board->leftRod[i] = 0;
      board->middleRod[i] = 0;
      board->rightRod[i] = 0;
   }
   return board;
}

/**
 * Determines whether or not the given board is valid.
 * A board is NOT valid, if it is 0.
 * 
 * @param board The board to evaluate.
 * @return If the given board is valid, false otherwise.
 */
bool tb_is_valid(TohBoard board)
{
   if (board != 0)
   {
      return true;
   }
   return false;
}

/**
 * Provides the top-most disk of the given rod and removes it from this rod.
 * 
 * @param board The board instance in focus.
 * @param rodName The rod from which the disk shall be taken and removed.
 * @return The removed disk or 0, if no disk was on the rod.
 */
Disk tb_pop_disk(TohBoard board, RodName rodName)
{
   Disk returnDisk;
   Disk targetRod[MAX_DISKS];
   if(tb_is_valid(board) == true)
   {
      switch (rodName)
      {
      case LEFT:
         for (int i = 0; i < MAX_DISKS; i++)
         {
            targetRod[i] = board->leftRod[i];
         }
         break;
      
      case MIDDLE:
         for (int i = 0; i < MAX_DISKS; i++)
         {
            targetRod[i] = board->middleRod[i];
         }
         break;

      case RIGHT:
         for (int i = 0; i < MAX_DISKS; i++)
         {
            targetRod[i] = board->rightRod[i];
         }
         break;

      default:
         return 0;
      }
      if (targetRod[0] == 0)
      {
         return 0;
      }
      else
      {
         for (int i = 0; i <= MAX_DISKS; i++)
         {
            if (targetRod[i] == 0)
            {
               switch (rodName)
               {
                  case LEFT:
                     returnDisk = board->leftRod[i - 1];
                     board->leftRod[i - 1] = 0;
                     break;
      
                  case MIDDLE:
                     returnDisk = board->middleRod[i - 1];
                     board->middleRod[i - 1] = 0;
                     break;

                  case RIGHT:
                     returnDisk = board->rightRod[i -1];
                     board->rightRod[i - 1] = 0;       
                     break;
               }
               return returnDisk;
            }
         }
      }
   }
   return 0;
}

/**
 * Applies the given disk to the given rod, if this 
 * is allowed according to the rules.
 * 
 * @param board The board instance in focus.
 * @param rodName The rod on which the disk shall be placed.
 * @param disk The disk to place on the rod.
 * @return True if the disk could be legally placed on the rod 
 * (move is allowed and disk is valid), false otherwise.
 */
bool tb_push_disk(TohBoard board, RodName rodName, Disk disk)
{
   if (tb_is_valid(board) == true && td_is_valid(disk) == true)
   {
      Disk targetRod[MAX_DISKS];
      switch (rodName)
      {
      case LEFT:
         for (int i = 0; i < MAX_DISKS; i++)
         {
            targetRod[i] = board->leftRod[i];
         }
         break;
      
      case MIDDLE:
         for (int i = 0; i < MAX_DISKS; i++)
         {
            targetRod[i] = board->middleRod[i];
         }
         break;

      case RIGHT:
         for (int i = 0; i < MAX_DISKS; i++)
         {
            targetRod[i] = board->rightRod[i];
         }
         break;

      default:
         return false;
      }
      if (targetRod[0] == 0)
      {
         switch (rodName)
         {
            case LEFT:
               board->leftRod[0] = disk;
               break;
      
            case MIDDLE:
               board->middleRod[0] = disk;
               break;

            case RIGHT:
               board->rightRod[0] = disk;       
               break;
         }
         return true;
      }
      else
      {
         for (int i = 0; i <= MAX_DISKS; i++)
         {
            if (targetRod[i] == 0)
            {
               if (td_is_smaller(targetRod[i -1], disk) == true)
               {
                  switch (rodName)
                  {
                     case LEFT:
                        board->leftRod[i] = disk;
                        break;
      
                     case MIDDLE:
                        board->middleRod[i] = disk;
                        break;

                     case RIGHT:
                        board->rightRod[i] = disk;       
                        break;
                  }
                  return true;
               }
            }
         }
      }
   }
   return false;
}

/**
 * Provides the disk from the named rod at the given position.
 * 
 * @param board The board instance in focus.
 * @param rodName The rod on which the disk shall be placed.
 * @param idx The index of the desired disk on the named rod. 
 *        Index 0 addresses the bottom-most disk.
 * @return The addressed disk or 0, if not disk is located on the
 *         index position of the named rod.
 */
Disk tb_get_disk(TohBoard board, RodName rodName, int idx)
{
   Disk returnDisk;
   if(tb_is_valid(board) == true && idx < MAX_DISKS)
   {
      switch (rodName)
      {
      case LEFT:
         returnDisk = board->leftRod[idx];
         break;
      
      case MIDDLE:
         returnDisk = board->middleRod[idx];
         break;

      case RIGHT:
         returnDisk = board->rightRod[idx];
         break;

      default:
         return 0;
      }
      return returnDisk;
   }
   return 0;
}

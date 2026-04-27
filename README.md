# Aptronics Tech Assessment - Suah Yi Hao

This is my Tech Assessment's project for the Aptronics company. 

## How to setup
1. Download the project folder from the 
	a. GitHub Link: https://github.com/Jimmyboyz/AptronicsTechAssessment.git
2. After the file is downloaded, you can open the unreal project by using Unreal Engine 5.5.4.
3. When inside the project, you should be inside the level called "ThirdPersonMap".

## How to run the project
1. After you are inside the level, can straight press the play button and test the game.
2. Inside the level, you will see 3 sections of Quest.
	a. The blue square will represent the NPC to giving task to the player.
	b. The white square will represent the objects that player interacts with to obtain the items/ defeat enemy.
	c. To interact, go close to the interact object (NPCs) and press "E" key.
	c. When the task is complete, it will pop up the `pring text` to show whether you done the quest or not.

# Short Report
### System Design
#### How the system setup?
1. Interact System
        a. The interact system will be using the blueprint interface to do the interaction.
		b. At the moment, I'm using the box volume on the NPC for detection.
2. Quest system
	a. All of the quest's details will be handle inside the Data Table call `DT_QuestData`.
	b. Inside the Data Table, it has `Quest Title`, `Quest Description`, `Required Main Quest` and `Required Completion Details`.
	c. `Row Name` will be the same as the Gameplay Tag, which it is set in the `QuestTag.ini`.
	d. Then there's an actor blueprint component called `BPC_QuestSystem`.
3. NPCs
	a. In this setup, they are the one that give player quest to do.
	b. It will check whether the player has the quest system component first, if there is, then it will pass the gameplay tag to the player's quest system and run the logic in there. 
	
#### How they communicate to each other?
1. When the player go near to the NPC and interact with it, it will check whether the player `Quest System` component, if there is, then the logic will proceed.
2. When adding the quest inside the quest system, it will check whether player has completed the test or not, if not, then it will check whether the selected quest has `Required Main Quest` to complete before accepting this new task.
3. If all criteria are met, then it will add this new quest to the `CuirrentQuestContainer` list to state that player has owned the quest.
4. Whenever player interact with the items, it will call the function `UpdateQuestSystem` in `BPC_QuestSystem` to update the list of the quest system that record how many quests'' requirement done.
5. If is `BPC_Quest System` detect the quests' requirement are match with the Data Table, then it will update the Quest System and set it to done.

# Key Challenges
### What challenges that I face and how I solved it?
1. When implement the Quest System, I was thinking what are the best method to use for set which NPC hold this specific quest, how to track how many quest that player need to consider finish and more.
	
	Solution: Use Data Table to setup the quest details and use it to do checking in actor component.

2. Which is the good method to setup for the Quest System for player?

	Solution: Set it as actor component blueprint, so that all of the logic will just inside the component, and as long as the playable character has the component, which mean this actor can do quest.

### Trade-offs and Improvements
1. The interact system was pretty simple and straight forward as I believe I would like to focus more on how the quest system can be scalable and editable in future cases.
	
	Future improvement: I would like to include line trace with timer to do confirm checking, so when player is inside the collision volume, line trace will start casting the line and timer will loop for every 0.5 seconds (can be adjust). When line cast detect on the item that can interact, then it will show up the UI, highlight interactable objects to state it can interact. When player exit the collision volume, it will check if there are any object still remain, if all are empty, it will disable the timer.

2. The current Quest System is enough to do most of the things, but there are things that can improve it to become better.

	Future Improvement: Can add in more details like what reward to receive after quest is success, set whether need to go back to the quest giver to claim reward and quest consider complete and more.  
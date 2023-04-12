# Action
```C++
//overide this
Result Action::perform(ENgine& engine) =0;
```
Remember that Actions contain a shared_ptr<Actor> called *actor*

## Results
similar to boolean but provides an extra option
Return these fomr Action::perform()
-success() it worked!
-failed() let me take another turn
-alternative(do_this_instead{})
*falied vs alternative*
if new positon is in the wall
    return failure()
If new position is a door
    return alternative(OpenDoor{})
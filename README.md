Unreal Plugin that allows the user to move an actor along a spline through the use of an actor component and level manager.

*Currently in beta status

__Planned features__
* Control Chaos Vehicles
* Control Skeletal meshes
* Callbacks for Spline position, Has Started, Has Finished
* Execute Movement


__Installation__

__PreCompiled__
  
Download the latest release and extract it to your project plugins folder

__From Source__
  
Download the repository and put it into your project's plugins folder.  Launch the editor and it should ask you to compile the plugin.
     
__Usage__

Plugin Contents

![PluginContent](https://github.com/thepinnacle317/LevelAnimator/assets/110754613/5eb3ddb6-eda5-4346-a1e2-548a40e6a499)


The level Manager is responsible for holding all the data related to the assigned actors through the use of the Actor Movement Data Data Asset (DA).
BP_Spline is the actor that holds the spline movement component that can be dragged into the level and then assigned to the level manager along with an actor

Like this:

![ActorData](https://github.com/thepinnacle317/LevelAnimator/assets/110754613/2912b228-139d-4d41-8b3d-aa62ed2936e4)


For an actor to follow the spline you must add the SplineMovementComponent to the actor.

![TestActor](https://github.com/thepinnacle317/LevelAnimator/assets/110754613/9bb1d63e-c028-443c-95c0-d895b346b5ea)



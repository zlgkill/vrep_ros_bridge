

#pragma once

#include <vrep_ros_plugin/GenericObjectHandler.h>
#include <shape_msgs/Mesh.h>


class DrawMeshHandler : public GenericObjectHandler
{
public:
	DrawMeshHandler();
	~DrawMeshHandler();

	/**
	 * @copydoc GenericObjectHandler::synchronize()
	 */
	void synchronize();

	/**
	 * @copydoc GenericObjectHandler::_initialize()
	 */
	bool endOfSimulation();

	/**
	 * @copydoc GenericObjectHandler::handleSimulation()
	 */
	void handleSimulation();

	/**
	 * @copydoc GenericObjectHandler::getObjectType()
	 */
	unsigned int getObjectType() const;

	const static unsigned int DATA_MAIN=900;

	const static unsigned int DATA_WIDTH = DATA_MAIN+1;
	const static unsigned int DATA_DIFFUSE = DATA_WIDTH+1;
	const static unsigned int DATA_SPECULAR = DATA_DIFFUSE+1;
	const static unsigned int DATA_EMISSION = DATA_SPECULAR+1;
	const static unsigned int DATA_TRANSPARENCY = DATA_EMISSION+1;


protected:

	/**
	 * Register custom lua variables for use in Lua scripts
	 */
	void registerCustomVariables() const;

	/**
	 * @copydoc GenericObjectHandler::_initialize()
	 */
	void _initialize();

	/**
	 * Subscriber for receiving line points.
	 */
	ros::Subscriber _sub;

	/**
	 * Last received message.
	 */
	shape_msgs::MeshConstPtr _lastMsg;

	/**
	 * Callback for velocity commands.
	 */
	void msgCallback(shape_msgs::MeshConstPtr msg);

	/**
	 * Simulation time of the last drawing.
	 */
	simFloat _lastTime;

	/**
	 * Drawing frequency
	 */
	simFloat _frequency;

	/**
	 * Drawing object handle
	 */
	simInt _drawingObject;


	simInt _width; /// Mesh line width
	simFloat _diffuse[3]; /// Mesh diffuse color
	simFloat _specular[3]; /// Mesh specular color
	simFloat _emission[3]; /// Mesh emission color
	simInt _transparency; /// Mesh transparency level: 0=100%, 1=50%, 2=25%, 3=12.5%
};

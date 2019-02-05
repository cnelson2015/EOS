clc, clear
%% STK Matlab scripting
try
    % Grab an existing instance of STK
    uiapp = actxGetRunningServer('STK11.application');
    root = uiapp.Personality2;
    checkempty = root.Children.Count;
    
catch
    % STK is not running, launch new instance
    % Launch a new instance of STK11 and grab it
    uiapp = actxserver('STK11.application');
    root = uiapp.Personality2;
    uiapp.visible = 1;
    root.NewScenario('Matlab_Automation_Test');
    scenario = root.CurrentScenario;
end

% Get the path to the STK install directory
installDirectory = root.ExecuteCommand('GetDirectory / STKHome').Item(0);

%% Script for commanding satellite in given scenario using Astrogator
% eSatellite enumeration = 18 with label 'EOS'
sat = scenario.Children.New(18,'EOS');
% Set the new Satellite to use Astrogator as the propagator
sat.SetPropagatorType('ePropagatorAstrogator');

%Create Astrogator object
ASTG = sat.Propagator;

% Create a handle to the Mission Control Sequence and remove all existing segments
MCS = ASTG.MainSequence;
MCS.RemoveAll;
%Give properties to the MCS
MCS.Insert('eVASegmentTypeInitialState','Inner Orbit','-');

%Initial State
% Keplerian elements and assign new initial values
initstate = MCS.Item('Inner Orbit');
initstate.OrbitEpoch = scenario.StartTime;
initstate.SetElementType('eVAElementTypeModKeplerian');
initstate.Element.RadiusOfPeriapsis = 400; %km?
initstate.Element.Eccentricity = 0;
initstate.Element.Inclination = 12; %degrees
initstate.Element.RAAN = 0;
initstate.Element.ArgOfPeriapsis = 0;
initstate.Element.TrueAnomaly = 0;


%%% Define a Target Sequence

% Insert a Target Sequence with a nested Maneuver segment
ts = MCS.Insert('eVASegmentTypeTargetSequence','Start Slew','-');

%%Add a sensor to the satellite
%create a camera
cam = sat.Children.New('eSensor', 'Camera');
cam.SetPointingType('eSensor','');
cam.invoke
%create a laser
%las = sat.Children.New('eSensor', 'Laser');


stk.v.11.0
WrittenBy    STK_v11.4.0

BEGIN Chain

    Name		 Sensor_ground
    BEGIN Definition

        Object		 Satellite/EOS/Sensor/LaserComm
        Object		 Place/FIT
        Type		 Chain
        FromOperator		 Or
        FromOrder		 1
        ToOperator		 Or
        ToOrder		 1
        Recompute		 Yes
        IntervalType		 0
        ComputeIntervalStart		 0
        ComputeIntervalStop		 3.1536e+07
        ComputeIntervalPtr		
        BEGIN EVENTINTERVAL
            BEGIN Interval
                Start		 10 Oct 2018 16:00:00.000000000
                Stop		 10 Oct 2019 16:00:00.000000000
            END Interval
            IntervalState		 Explicit
        END EVENTINTERVAL

        ConstraintsUseStrandTimes		 Yes
        UseSaveIntervalFile		 No
        SaveIntervalFile		 C:\Users\Connor\Documents\STK 11 (x64)\Sat_test\strand.int
        UseMinAngle		 No
        UseMaxAngle		 No
        UseMinLinkTime		 No
        LTDelayCriterion		 2
        TimeConvergence		 0.005
        AbsValueConvergence		 1e-14
        RelValueConvergence		 1e-08
        MaxTimeStep		 360
        MinTimeStep		 0.01
        UseLightTimeDelay		 Yes
        DetectEventsUsingSamplesOnly		 No
        UseLoadIntervalFile		 No
        BEGIN StrandObjIndexes
            StrandObj		 Satellite/EOS/Sensor/LaserComm
            StrandObj		 Place/FIT
        END StrandObjIndexes

        SaveMode		 1
        BEGIN StrandAccessesByIndex
            Strand		 0 1
            Start		 2.7990743843124560e+06
            Stop		 2.7990794640998635e+06
            Start		 3.1081911213289062e+06
            Stop		 3.1081956935133883e+06
            Start		 7.3883772456777198e+06
            Stop		 7.3883817950248830e+06
            Start		 7.6974945111353006e+06
            Stop		 7.6974975027016643e+06
            Start		 9.3123561950560939e+06
            Stop		 9.3123589255552124e+06
            Start		 1.1977680624979211e+07
            Stop		 1.1977683591359708e+07
            Start		 1.3592542255483424e+07
            Stop		 1.3592545049884336e+07
            Start		 1.3901657914339319e+07
            Stop		 1.3901662372063739e+07
            Start		 1.8181843999402747e+07
            Stop		 1.8181848466785830e+07
            Start		 1.8490960175603602e+07
            Stop		 1.8490965243376110e+07
            Start		 2.2771146365396507e+07
            Stop		 2.2771151438131578e+07
            Start		 2.3080262931531940e+07
            Stop		 2.3080267809618134e+07
            Start		 2.7360449112133633e+07
            Stop		 2.7360453973425794e+07
            Start		 2.7669566102481533e+07
            Stop		 2.7669569951929882e+07
            Start		 2.9284429388614580e+07
            Stop		 2.9284429621685002e+07
        END StrandAccessesByIndex


    END Definition

    BEGIN Extensions

        BEGIN ADFFileData
        END ADFFileData

        BEGIN Desc
        END Desc

        BEGIN Crdn
        END Crdn

        BEGIN Graphics

            BEGIN Attributes

                StaticColor		 #ff00ff
                AnimationColor		 #00ff00
                AnimationLineWidth		 2
                StaticLineWidth		 3

            END Attributes

            BEGIN Graphics
                ShowGfx		 On
                ShowStatic		 Off
                ShowAnimationHighlight		 On
                ShowAnimationLine		 On
                ShowLinkDirection		 Off
            END Graphics
        END Graphics

        BEGIN VO
        END VO

    END Extensions

END Chain



using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml;
using CRA.ModelLayer.MetadataTypes;
using CRA.ModelLayer.Core;
using CRA.ModelLayer.Strategy;
using System.Reflection;
using VarInfo=CRA.ModelLayer.Core.VarInfo;
using Preconditions=CRA.ModelLayer.Core.Preconditions;
using CRA.AgroManagement;       
using Phenology.DomainClass;
namespace Phenology.Strategies
{
    public class UpdateCalendar : IStrategyPhenology
    {
        public UpdateCalendar()
        {
            ModellingOptions mo0_0 = new ModellingOptions();
            //Parameters
            List<VarInfo> _parameters0_0 = new List<VarInfo>();
            mo0_0.Parameters=_parameters0_0;

            //Inputs
            List<PropertyDescription> _inputs0_0 = new List<PropertyDescription>();
            PropertyDescription pd1 = new PropertyDescription();
            pd1.DomainClassType = typeof(Phenology.DomainClass.PhenologyAuxiliary);
            pd1.PropertyName = "cumulTT";
            pd1.PropertyType = (Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTT).ValueType.TypeForCurrentValue;
            pd1.PropertyVarInfo =(Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTT);
            _inputs0_0.Add(pd1);
            PropertyDescription pd2 = new PropertyDescription();
            pd2.DomainClassType = typeof(Phenology.DomainClass.PhenologyState);
            pd2.PropertyName = "calendarMoments";
            pd2.PropertyType = (Phenology.DomainClass.PhenologyStateVarInfo.calendarMoments).ValueType.TypeForCurrentValue;
            pd2.PropertyVarInfo =(Phenology.DomainClass.PhenologyStateVarInfo.calendarMoments);
            _inputs0_0.Add(pd2);
            PropertyDescription pd3 = new PropertyDescription();
            pd3.DomainClassType = typeof(Phenology.DomainClass.PhenologyState);
            pd3.PropertyName = "calendarDates";
            pd3.PropertyType = (Phenology.DomainClass.PhenologyStateVarInfo.calendarDates).ValueType.TypeForCurrentValue;
            pd3.PropertyVarInfo =(Phenology.DomainClass.PhenologyStateVarInfo.calendarDates);
            _inputs0_0.Add(pd3);
            PropertyDescription pd4 = new PropertyDescription();
            pd4.DomainClassType = typeof(Phenology.DomainClass.PhenologyState);
            pd4.PropertyName = "calendarCumuls";
            pd4.PropertyType = (Phenology.DomainClass.PhenologyStateVarInfo.calendarCumuls).ValueType.TypeForCurrentValue;
            pd4.PropertyVarInfo =(Phenology.DomainClass.PhenologyStateVarInfo.calendarCumuls);
            _inputs0_0.Add(pd4);
            PropertyDescription pd5 = new PropertyDescription();
            pd5.DomainClassType = typeof(Phenology.DomainClass.PhenologyAuxiliary);
            pd5.PropertyName = "currentdate";
            pd5.PropertyType = (Phenology.DomainClass.PhenologyAuxiliaryVarInfo.currentdate).ValueType.TypeForCurrentValue;
            pd5.PropertyVarInfo =(Phenology.DomainClass.PhenologyAuxiliaryVarInfo.currentdate);
            _inputs0_0.Add(pd5);
            PropertyDescription pd6 = new PropertyDescription();
            pd6.DomainClassType = typeof(Phenology.DomainClass.PhenologyState);
            pd6.PropertyName = "phase";
            pd6.PropertyType = (Phenology.DomainClass.PhenologyStateVarInfo.phase).ValueType.TypeForCurrentValue;
            pd6.PropertyVarInfo =(Phenology.DomainClass.PhenologyStateVarInfo.phase);
            _inputs0_0.Add(pd6);
            mo0_0.Inputs=_inputs0_0;

            //Outputs
            List<PropertyDescription> _outputs0_0 = new List<PropertyDescription>();
            PropertyDescription pd7 = new PropertyDescription();
            pd7.DomainClassType = typeof(Phenology.DomainClass.PhenologyState);
            pd7.PropertyName = "calendarMoments";
            pd7.PropertyType = (Phenology.DomainClass.PhenologyStateVarInfo.calendarMoments).ValueType.TypeForCurrentValue;
            pd7.PropertyVarInfo =(Phenology.DomainClass.PhenologyStateVarInfo.calendarMoments);
            _outputs0_0.Add(pd7);
            mo0_0.Outputs=_outputs0_0;PropertyDescription pd8 = new PropertyDescription();
            pd8.DomainClassType = typeof(Phenology.DomainClass.PhenologyState);
            pd8.PropertyName = "calendarDates";
            pd8.PropertyType = (Phenology.DomainClass.PhenologyStateVarInfo.calendarDates).ValueType.TypeForCurrentValue;
            pd8.PropertyVarInfo =(Phenology.DomainClass.PhenologyStateVarInfo.calendarDates);
            _outputs0_0.Add(pd8);
            mo0_0.Outputs=_outputs0_0;PropertyDescription pd9 = new PropertyDescription();
            pd9.DomainClassType = typeof(Phenology.DomainClass.PhenologyState);
            pd9.PropertyName = "calendarCumuls";
            pd9.PropertyType = (Phenology.DomainClass.PhenologyStateVarInfo.calendarCumuls).ValueType.TypeForCurrentValue;
            pd9.PropertyVarInfo =(Phenology.DomainClass.PhenologyStateVarInfo.calendarCumuls);
            _outputs0_0.Add(pd9);
            mo0_0.Outputs=_outputs0_0;
            //Associated strategies
            List<string> lAssStrat0_0 = new List<string>();
            mo0_0.AssociatedStrategies = lAssStrat0_0;
            //Adding the modeling options to the modeling options manager
            _modellingOptionsManager = new ModellingOptionsManager(mo0_0);
            SetStaticParametersVarInfoDefinitions();
            SetPublisherData();

        }

        public string Description
        {
            get { return "Lists containing for each stage the date it occurs as well as a copy of all types of cumulated thermal times " ;}
        }

        public string URL
        {
            get { return "" ;}
        }

        public string Domain
        {
            get { return "";}
        }

        public string ModelType
        {
            get { return "";}
        }

        public bool IsContext
        {
            get { return false;}
        }

        public IList<int> TimeStep
        {
            get
            {
                IList<int> ts = new List<int>();
                return ts;
            }
        }

        private  PublisherData _pd;
        public PublisherData PublisherData
        {
            get { return _pd;} 
        }

        private  void SetPublisherData()
        {
            _pd = new CRA.ModelLayer.MetadataTypes.PublisherData();
            _pd.Add("Creator", "Pierre Martre");
            _pd.Add("Date", "");
            _pd.Add("Publisher", "INRA Montpellier");
        }

        private ModellingOptionsManager _modellingOptionsManager;
        public ModellingOptionsManager ModellingOptionsManager
        {
            get { return _modellingOptionsManager; } 
        }

        public IEnumerable<Type> GetStrategyDomainClassesTypes()
        {
            return new List<Type>() {  typeof(Phenology.DomainClass.PhenologyState),  typeof(Phenology.DomainClass.PhenologyState), typeof(Phenology.DomainClass.PhenologyRate), typeof(Phenology.DomainClass.PhenologyAuxiliary), typeof(Phenology.DomainClass.PhenologyExogenous)};
        }

        // Getter and setters for the value of the parameters of the strategy. The actual parameters are stored into the ModelingOptionsManager of the strategy.


        public void SetParametersDefaultValue()
        {
            _modellingOptionsManager.SetParametersDefaultValue();
        }

        private static void SetStaticParametersVarInfoDefinitions()
        {
        }

        public string TestPostConditions(Phenology.DomainClass.PhenologyState s,Phenology.DomainClass.PhenologyState s1,Phenology.DomainClass.PhenologyRate r,Phenology.DomainClass.PhenologyAuxiliary a,Phenology.DomainClass.PhenologyExogenous ex,string callID)
        {
            try
            {
                //Set current values of the outputs to the static VarInfo representing the output properties of the domain classes
                Phenology.DomainClass.PhenologyStateVarInfo.calendarMoments.CurrentValue=s.calendarMoments;
                Phenology.DomainClass.PhenologyStateVarInfo.calendarDates.CurrentValue=s.calendarDates;
                Phenology.DomainClass.PhenologyStateVarInfo.calendarCumuls.CurrentValue=s.calendarCumuls;
                ConditionsCollection prc = new ConditionsCollection();
                Preconditions pre = new Preconditions(); 
                RangeBasedCondition r7 = new RangeBasedCondition(Phenology.DomainClass.PhenologyStateVarInfo.calendarMoments);
                if(r7.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyStateVarInfo.calendarMoments.ValueType)){prc.AddCondition(r7);}
                RangeBasedCondition r8 = new RangeBasedCondition(Phenology.DomainClass.PhenologyStateVarInfo.calendarDates);
                if(r8.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyStateVarInfo.calendarDates.ValueType)){prc.AddCondition(r8);}
                RangeBasedCondition r9 = new RangeBasedCondition(Phenology.DomainClass.PhenologyStateVarInfo.calendarCumuls);
                if(r9.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyStateVarInfo.calendarCumuls.ValueType)){prc.AddCondition(r9);}
                string postConditionsResult = pre.VerifyPostconditions(prc, callID); if (!string.IsNullOrEmpty(postConditionsResult)) { pre.TestsOut(postConditionsResult, true, "PostConditions errors in strategy " + this.GetType().Name); } return postConditionsResult;
            }
            catch (Exception exception)
            {
                string msg = ".Phenology, " + this.GetType().Name + ": Unhandled exception running post-condition test. ";
                throw new Exception(msg, exception);
            }
        }

        public string TestPreConditions(Phenology.DomainClass.PhenologyState s,Phenology.DomainClass.PhenologyState s1,Phenology.DomainClass.PhenologyRate r,Phenology.DomainClass.PhenologyAuxiliary a,Phenology.DomainClass.PhenologyExogenous ex,string callID)
        {
            try
            {
                //Set current values of the inputs to the static VarInfo representing the inputs properties of the domain classes
                Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTT.CurrentValue=a.cumulTT;
                Phenology.DomainClass.PhenologyStateVarInfo.calendarMoments.CurrentValue=s.calendarMoments;
                Phenology.DomainClass.PhenologyStateVarInfo.calendarDates.CurrentValue=s.calendarDates;
                Phenology.DomainClass.PhenologyStateVarInfo.calendarCumuls.CurrentValue=s.calendarCumuls;
                Phenology.DomainClass.PhenologyAuxiliaryVarInfo.currentdate.CurrentValue=a.currentdate;
                Phenology.DomainClass.PhenologyStateVarInfo.phase.CurrentValue=s.phase;
                ConditionsCollection prc = new ConditionsCollection();
                Preconditions pre = new Preconditions(); 
                RangeBasedCondition r1 = new RangeBasedCondition(Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTT);
                if(r1.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyAuxiliaryVarInfo.cumulTT.ValueType)){prc.AddCondition(r1);}
                RangeBasedCondition r2 = new RangeBasedCondition(Phenology.DomainClass.PhenologyStateVarInfo.calendarMoments);
                if(r2.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyStateVarInfo.calendarMoments.ValueType)){prc.AddCondition(r2);}
                RangeBasedCondition r3 = new RangeBasedCondition(Phenology.DomainClass.PhenologyStateVarInfo.calendarDates);
                if(r3.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyStateVarInfo.calendarDates.ValueType)){prc.AddCondition(r3);}
                RangeBasedCondition r4 = new RangeBasedCondition(Phenology.DomainClass.PhenologyStateVarInfo.calendarCumuls);
                if(r4.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyStateVarInfo.calendarCumuls.ValueType)){prc.AddCondition(r4);}
                RangeBasedCondition r5 = new RangeBasedCondition(Phenology.DomainClass.PhenologyAuxiliaryVarInfo.currentdate);
                if(r5.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyAuxiliaryVarInfo.currentdate.ValueType)){prc.AddCondition(r5);}
                RangeBasedCondition r6 = new RangeBasedCondition(Phenology.DomainClass.PhenologyStateVarInfo.phase);
                if(r6.ApplicableVarInfoValueTypes.Contains( Phenology.DomainClass.PhenologyStateVarInfo.phase.ValueType)){prc.AddCondition(r6);}
                string preConditionsResult = pre.VerifyPreconditions(prc, callID); if (!string.IsNullOrEmpty(preConditionsResult)) { pre.TestsOut(preConditionsResult, true, "PreConditions errors in strategy " + this.GetType().Name); } return preConditionsResult;
            }
            catch (Exception exception)
            {
                string msg = ".Phenology, " + this.GetType().Name + ": Unhandled exception running pre-condition test. ";
                throw new Exception(msg, exception);
            }
        }

        public void Estimate(Phenology.DomainClass.PhenologyState s,Phenology.DomainClass.PhenologyState s1,Phenology.DomainClass.PhenologyRate r,Phenology.DomainClass.PhenologyAuxiliary a,Phenology.DomainClass.PhenologyExogenous ex)
        {
            try
            {
                CalculateModel(s, s1, r, a, ex);
            }
            catch (Exception exception)
            {
                string msg = "Error in component Phenology, strategy: " + this.GetType().Name + ": Unhandled exception running model. "+exception.GetType().FullName+" - "+exception.Message;
                throw new Exception(msg, exception);
            }
        }

        private void CalculateModel(Phenology.DomainClass.PhenologyState s, Phenology.DomainClass.PhenologyState s1, Phenology.DomainClass.PhenologyRate r, Phenology.DomainClass.PhenologyAuxiliary a, Phenology.DomainClass.PhenologyExogenous ex)
        {
            double cumulTT = a.cumulTT;
            List<string> calendarMoments = s.calendarMoments;
            List<DateTime> calendarDates = s.calendarDates;
            List<double> calendarCumuls = s.calendarCumuls;
            DateTime currentdate = a.currentdate;
            double phase = s.phase;
            if (phase >= 1.0d && phase < 2.0d && !calendarMoments.Contains("Emergence"))
            {
                calendarMoments.Add("Emergence");
                calendarCumuls.Add(cumulTT);
                calendarDates.Add(currentdate);
            }
            else if ( phase >= 2.0d && phase < 3.0d && !calendarMoments.Contains("FloralInitiation"))
            {
                calendarMoments.Add("FloralInitiation");
                calendarCumuls.Add(cumulTT);
                calendarDates.Add(currentdate);
            }
            else if ( phase >= 3.0d && phase < 4.0d && !calendarMoments.Contains("Heading"))
            {
                calendarMoments.Add("Heading");
                calendarCumuls.Add(cumulTT);
                calendarDates.Add(currentdate);
            }
            else if ( phase == 4.0d && !calendarMoments.Contains("Anthesis"))
            {
                calendarMoments.Add("Anthesis");
                calendarCumuls.Add(cumulTT);
                calendarDates.Add(currentdate);
            }
            else if ( phase == 4.5d && !calendarMoments.Contains("EndCellDivision"))
            {
                calendarMoments.Add("EndCellDivision");
                calendarCumuls.Add(cumulTT);
                calendarDates.Add(currentdate);
            }
            else if ( phase >= 5.0d && phase < 6.0d && !calendarMoments.Contains("EndGrainFilling"))
            {
                calendarMoments.Add("EndGrainFilling");
                calendarCumuls.Add(cumulTT);
                calendarDates.Add(currentdate);
            }
            else if ( phase >= 6.0d && phase < 7.0d && !calendarMoments.Contains("Maturity"))
            {
                calendarMoments.Add("Maturity");
                calendarCumuls.Add(cumulTT);
                calendarDates.Add(currentdate);
            }
            s.calendarMoments= calendarMoments;
            s.calendarDates= calendarDates;
            s.calendarCumuls= calendarCumuls;
        }

    }
}